//
// Created by JMKov on 8/15/2024.
//
#include <iostream>
using namespace std;

const long long INF = 100000000000;

long long n;
long long arr[104];
long long dp[104][104];

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];

    for (long long i = 0; i < n; i++) for (long long j = 0; j <= n; j++) {
        dp[i][j] = INF;
    }
    for (long long i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }

    for (long long i = 0; i < n; i++) {
        long long l = max(i - arr[i] + 1, 0ll);
        long long r = min(i + arr[i] - 1, n - 1);
        for (long long j = 0; j <= n; j++) {
            dp[i][j] = min(dp[i][j], (i == 0) ? INF : dp[i - 1][j]);
            if (j > l - 1) {
                dp[i][i + 1] = min(dp[i][i + 1], (i == 0) ? 1 : dp[i - 1][j] + 1);
            }
            if (j > i - 1) {
                dp[i][r + 1] = min(dp[i][r + 1], (i == 0) ? 1 : dp[i - 1][j] + 1);
            }
            if (j > l - 1 && j < i) {
                long long r2 = min(j + arr[j] - 1, n - 1);
                dp[i][r2 + 1] = min(dp[i][r2 + 1], (j == 0) ? 2 : dp[j - 1][max(l, 0ll)] + 2);
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            dp[i][j] = min(dp[i][j], dp[i][j + 1]);
        }
    }
    cout << dp[n - 1][n] << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
