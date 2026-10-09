//
// Created by JMKov on 7/31/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, k;
long long sum[200005];
long long dp[3][200005];
long long arr[200005];

int main() {
    cin >> n >> k;
    dp[1][0] = 1;
    sum[0] = 1;
    arr[0] = dp[1][k - 2];
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j <= k - 1; j++) {
            dp[2][j] = sum[j - 1] - dp[0][j - 1];
            dp[2][j] += mod * 10000;
            dp[2][j] %= mod;
        }
        dp[2][k - 2] += dp[2][k - 1]; // this is not gonna work lmfao
        dp[2][k - 2] %= mod;
        dp[2][k - 1] = 0;
        for (long long j = 0; j <= k - 2; j++) {
            sum[j] += dp[2][j];
            sum[j] %= mod;
        }
        arr[i + 1] = dp[2][k - 2];
        for (long long j = 0; j <= k - 2; j++) {
            dp[0][j] = dp[1][j];
            dp[1][j] = dp[2][j];
            dp[2][j] = 0;
        }
    }
    long long ans = 0;
    for (long long i = 0; i <= n; i++) {
        ans += max(0ll, n - 1 - i) * arr[i] % mod;
        ans %= mod;
//        cout << arr[i] << " ";
    }
//    cout << endl;
    cout << ans << endl;
    return 0;
}
