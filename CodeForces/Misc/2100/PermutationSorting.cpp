#include <bits/stdc++.h>
using namespace std;

#define REP(i, s, e) for (int i = (s); i < (e); i++)
#define RREP(i, s, e) for (int i = (s); i >= (e); i--)
#define ALL(_a) _a.begin(), _a.end()
#define SZ(_a) (int) _a.size()

const int INF = 1000000005;
const int MAXN = 1000005;

int t;
int n;
int p[MAXN];
int ans[MAXN];

int fw[MAXN * 2];
void incre(int i, int x) {
    for (; i <= 2 * n; i += i & -i) {
        fw[i] += x;
    }
}
int qsm(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fw[i];
    }
    return res;
}
inline int qsm(int s, int e) {
    return qsm(e) - qsm(s - 1);
}

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> t;
    while (t--) {
        cin >> n;
        REP (i, 1, n + 1) {
            cin >> p[i];
        }
        REP (i, 0, 2 * n + 5) {
            fw[i] = 0;
        }
        vector<pair<int, int>> rgs;
        REP (i, 1, n + 1) {
            if (i <= p[i]) {
                rgs.push_back({i, p[i]});
                rgs.push_back({i + n, p[i] + n});
            } else {
                rgs.push_back({i, p[i] + n});
            }
        }
        sort(ALL(rgs), greater<pair<int, int>>());
        for (auto [l, r] : rgs) {
            if (l <= n) {
                ans[p[l]] = r - l - qsm(l, r);
            }
            incre(r, 1);
        }
        REP (i, 1, n + 1) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}