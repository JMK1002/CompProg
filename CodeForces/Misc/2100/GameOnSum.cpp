//
// Created by JMKov on 7/25/2024.
//
#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long n, m, k;
long long dp[2005][2005];

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
    cin >> n >> m >> k;
    for (long long i = 0; i <= n; i++) {
        dp[i][0] = 0;
        dp[i][i] = k * i % mod;
    }
    for (long long i = 1; i <= n; i++) {
        for (long long j = i + 1; j <= n; j++) {
            dp[j][i] = (dp[j - 1][i] + dp[j - 1][i - 1]) % mod * inv(2) % mod;
        }
    }
    cout << dp[n][m] << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}