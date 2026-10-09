//
// Created by JMKov on 6/26/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, k;
long long dp[2502][2502]; // dp[n][zeros on back]

void solve() {
    cin >> n >> k;
//    n = 1; k = 2500;
    dp[0][0] = 1;
    for (long long i = 1; i < 2500; i++) {
        dp[0][i] = 1;
    }
    for (long long i = 1; i <= n; i++) {
        for (long long j = 0; j <= 2500; j++) {
            for (long long l = 0; j + 1 + l <= k && i - (l + 1) * (j + 1) >= 0; l++) {
                dp[i][j] += dp[i - (l + 1) * (j + 1)][l];
                dp[i][j] %= mod;
            }
        }
    }
    long long ans = 0;
    for (long long i = 0; i < k; i++) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
    for (long long i = 1; i <= n; i++) {
        for (long long j = 0; j <= 2500; j++) {
            if (j + 1 <= k && i - (j + 1) >= 0) {
                dp[i][j] = 0;
            }
            else {
                break;
            }
//            cout << dp[i][j] << " ";
        }
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}