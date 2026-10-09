//
// Created by JMKov on 7/29/2023.
//
#include <iostream>
using namespace std;

long long dp[300010][3][3];

int main() {
    long long n, x;
    cin >> n >> x;
    long long arr[n];

    for (long long i = 0; i <= n; i++) for (long long j = 0; j < 3; j++) for (long long k = 0; k < 3; k++) {
        dp[i][j][k] = INT64_MIN;
    }

    dp[0][0][0] = 0;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 0; i <= n; i++) {
        for (long long j = 0; j < 3; j++) {
            for (long long k = 0; k < 3; k++) {
                if (k < 2)
                    dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
                if (j < 2)
                    dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
                if (i < n)
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? arr[i] : 0) * (k == 1 ? x : 1));
            }
        }
    }
    cout << dp[n][2][2] << endl;
    return 0;
}