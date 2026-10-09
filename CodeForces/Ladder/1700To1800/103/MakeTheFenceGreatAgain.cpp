//
// Created by JMKov on 7/16/2023.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        pair<long long, long long> arr[n];
        long long dp[n][3];
        for (long long i = 0; i < n; i++) {
            cin >> arr[i].first >> arr[i].second;
        }
        dp[0][0] = 0;
        dp[0][1] = dp[0][0] + arr[0].second;
        dp[0][2] = dp[0][1] + arr[0].second;
        for (long long i = 1; i < n; i++) {
            for (long long k = 0; k < 3; k++) {
                dp[i][k] = INT64_MAX;
                for (long long j = 0; j < 3; j++) {
                    if (arr[i - 1].first + j == arr[i].first + k) continue;
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + arr[i].second * k);
                }
            }
        }
//        for (long long i = 0; i < n; i++) {
//            cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
//        }
        long long ans = min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
        cout << ans << endl;
    }
    return 0;
}
//2 6 10
//6 3 4
//4 8 13
//4