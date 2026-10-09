#include <iostream>
using namespace std;

long long n;
long long arr[5005];
long long dp[5005][5005];
long long pre[5005][5005];

const long long mod = 998244353;

long long binpow(long long a, long long b) {
    long long res = 1;
    long long run = a;
    while (b) {
        if (b & 1) res *= run;
        res %= mod;
        b >>= 1;
        run *= run;
        run %= mod;
    }
    return res % mod;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    dp[2][1] = 1;
    pre[2][1] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            dp[i][j] += pre[i - 1][j - 1];
            dp[i][j] %= mod;
            dp[i][j] += dp[i - 1][j] * (arr[i] > arr[i - 1]);
            dp[i][j] %= mod;
            dp[i][j] *= binpow(2, i - j - 1);
            dp[i][j] %= mod;

            pre[i][j] = pre[i][j - 1] + dp[i][j];
            pre[i][j] %= mod;
        }
    }
    cout << pre[n][n - 1] << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
            pre[i][j] = 0;
        }
        arr[i] = 0;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}