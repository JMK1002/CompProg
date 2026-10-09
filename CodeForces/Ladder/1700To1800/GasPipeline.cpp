//
// Created by JMKov on 6/12/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;
        string s;
        cin >> s;
        long long dp[2][n];
        for (long long i = 0; i < n; i++) {
            dp[0][i] = 1e18;
            dp[1][i] = 1e18;
        }
        dp[0][0] = a + b;
        dp[1][0] = 2 * a + b;
        for (long long i = 1; i < n; i++) {
            if (s[i] == '0') {
                dp[0][i] = min(dp[0][i - 1] + a + b, dp[1][i - 1] + 2 * a + 2 * b);
                dp[1][i] = min(dp[0][i - 1] + 2 * a + b, dp[1][i - 1] + a + 2 * b);
            }
            else {
                dp[1][i] = dp[1][i - 1] + a + 2 * b;
            }
        }
//        for (long long i : dp[1]) cout << i << " ";
//        cout << endl;
//        for (long long i : dp[0]) cout << i << " ";
//        cout << endl;
        cout << dp[0][n - 1] + b << endl;
    }
    return 0;
}