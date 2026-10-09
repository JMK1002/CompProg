//
// Created by JMKov on 10/16/2023.
//
#include <iostream>
using namespace std;

int dp[4][200000];

void solve(int n, int * arr) {
    dp[0][0] = arr[0];
    dp[1][0] = -1 * arr[0];
    dp[2][0] = arr[0];
    dp[3][0] = max(arr[0], -1 * arr[0]);
    for (int i = 1; i < n; i++) {
        dp[0][i] = max(dp[0][i - 1] + arr[i], arr[i]);
        dp[1][i] = max(dp[1][i - 1] - arr[i], dp[0][i - 1] - arr[i]);
        dp[2][i] = max(dp[2][i - 1] + arr[i], dp[1][i - 1] + arr[i]);
        dp[3][i] = max(dp[3][i - 1], max(dp[2][i], max(dp[1][i], max(dp[0][i], 0))));
    }
    cout << dp[3][n - 1] << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solve(n, arr);
    }
    return 0;
}