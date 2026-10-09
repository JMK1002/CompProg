#include <bits/stdc++.h>

using namespace std;

template<class T> bool ckmin(T &a, T b) {return a > b ? a=b, true : false;}

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define sz(v) (int)v.size()
#define all(v) v.begin(),v.end()

struct option {
    int t, p, id;
    option(int _t,int _p, int _id) : t(_t), p(_p), id(_id) {
    }
};

const int INF = INT_MAX >> 1;

vector<int> get_ans(vector<option> &v) {
    int n = sz(v);
    vector<vector<int>> dp(101, vector<int>(n+1, INF));
    dp[0][0] = 0;
    for (int k = 1; k <= n; k++) {
        auto [t,p,id] = v[k-1];
        dp[0][k] = 0;
        for (int i = 100; i > 0; i--) {
            int prev = max(0,i - p);
            dp[i][k] = dp[i][k-1];
            ckmin(dp[i][k], dp[prev][k-1] + t);
        }
    }
    vector<int> ans;
    int t = dp[100][n];

    if (t == INF) return {-1};
    for (int i = 100, k = n; k >= 1; k--) {
        if (dp[i][k] == dp[i][k-1]) {
            continue;
        }
        ans.emplace_back(v[k-1].id);
        i = max(0, i - v[k-1].p);
    }

    reverse(all(ans));
    ans.emplace_back(t);
    return ans;
}

void solve(bool flag=true) {


    int n,m; cin >> n >> m;
    vector<int> a(n);
    forn(i, n) {
        cin >> a[i];
    }
    for (int i = n-1; i > 0; i--) {
        a[i] -= a[i-1];
    }

    vector<vector<option>> v(n);
    forn(j, m) {
        int e,t,p; cin >> e >> t >> p, e--;
        v[e].emplace_back(t, p, j+1);
    }
    vector<int> ans;
    forn(i, n) {
        vector<int> cur = get_ans(v[i]);
        if (sz(cur) == 1 && cur[0] == -1) {
            cout << "-1\n";
            return;
        }
        int t = cur.back();
        if (t > a[i]) {
            cout << "-1\n";
            return;
        }
        cur.pop_back();
        if (i+1 < n) a[i+1] += a[i] - t;

        ans.insert(ans.end(), all(cur));
    }


    cout << sz(ans) << '\n';
    for (auto e:ans) cout << e << ' ';
    cout << '\n';
}

int main() {
    int t;
    cin >> t;

    forn(tt, t) {
        solve();
    }
}