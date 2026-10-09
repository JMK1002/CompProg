#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define allr(x) (x).rbegin(), (x).rend()
#define gsize(x) (int)((x).size())

const char nl = '\n';
typedef long long ll;
typedef long double ld;

using namespace std;

const int inf = 1000000000;

bool f(vector<int> a, int k, int ans) {
    int n = gsize(a);
    int dk = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] * 2 < ans) {
            a[i] = inf;
            k--;
            dk++;
        }
    }

    if (k < 0) return false;
    if ((k > 0 && dk > 0) || k >= 2) return true;

    if (k == 1 && dk == 0) {
        return *max_element(all(a)) >= ans;
    }

    for (int i = 0; i < n - 1; i++) {
        if (min(a[i], a[i + 1]) >= ans) return true;
    }

    return false;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int lb = 0, ub = inf, tans = 0;
    while (lb <= ub) {
        int tm = (lb + ub) / 2;
        if (f(a, k, tm)) {
            tans = tm;
            lb = tm + 1;
        } else {
            ub = tm - 1;
        }
    }

    cout << tans << nl;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;
    while (T--) solve();
}