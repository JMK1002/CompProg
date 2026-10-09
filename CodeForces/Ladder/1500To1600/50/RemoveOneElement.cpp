#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define fi first
#define se second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define each(v, a) for (auto v: (a))
#define all(a) (a).begin(), (a).end()

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 2e5 + 5;

int a[N];
int f[2][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // freopen("file.inp", "r", stdin);
    // freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    FOR(i, 1, n + 1) cin >> a[i];
    int ans = 0;
    FOR(i, 1, n + 1) {
        if (a[i] > a[i-1]) {
            f[0][i] = f[0][i-1] + 1;
            f[1][i] = f[1][i-1] + 1;
        }
        else {
            f[0][i] = 1;
            f[1][i] = 1;
        }
        if (i >= 3 && a[i] > a[i-2]) {
            f[1][i] = max(f[1][i], f[0][i-2] + 1);
        }
        ans = max(ans, max(f[1][i], f[0][i]));
    }
    cout << ans;

    return 0;
}

/*
==================================================+
INPUT                                             |
--------------------------------------------------|
5
1 2 3 1 4
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/


