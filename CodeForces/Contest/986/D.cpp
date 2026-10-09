#include <iostream>
#include <stack>
#include <set>
#include <vector>
using namespace std;

set<pair<long long, long long>> adj[200010];
bool reachable[200010];
long long p[3][200010];

void solve() { 
    long long n;
    cin >> n;
    for (long long i = 0; i < 3; i++) {
        for (long long j = 0; j < n; j++) {
            cin >> p[i][j];
            // p[i][j] = (2 * n - j - 2 - i) % n + 1;
        }
    }
    for (long long i = 0; i < 3; i++) {
        stack<pair<long long, long long>> st;
        for (long long j = 0; j < n; j++) {
            while (!st.empty() && st.top().first > p[i][j]) {
                adj[st.top().second].emplace(j + 1, i);
                st.pop();
            }
            st.emplace(p[i][j], j + 1);
        }
    }
    set<pair<long long, long long>> asdf;
    vector<pair<long long, long long>> ans;
    reachable[1] = true;
    for (long long i = 1; i <= n; i++) {
        for (pair<long long, long long> p : adj[i]) asdf.insert(p);
        if (!reachable[i] || asdf.empty()) continue;
        reachable[(*--asdf.end()).first] = true;
        ans.push_back((*--asdf.end()));
    }
    if (reachable[n]) {
        cout << "YES" << endl;
        long long basdf = 0;
        for (long long i = 0; i < ans.size(); i++) {
            if (i != 0 && ans[i] == ans[i - 1]) basdf++;
        }
        cout << ans.size() - basdf << endl;
        for (long long i = 0; i < ans.size(); i++) {
            if (i != 0 && ans[i] == ans[i - 1]) continue;
            cout << (ans[i].second == 0 ? 'q' : (ans[i].second == 1) ? 'k' : 'j') << " " << ans[i].first << endl;
        }
    }
    else {
        cout << "NO" << endl;
    }
    for (long long i = 0; i <= n; i++) {
        reachable[i] = 0;
        for (long long j = 0; j < 3; j++) p[j][i] = 0;
        adj[i].clear();
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}