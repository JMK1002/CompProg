//
// Created by JMKov on 6/20/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool dp[n];
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            dp[i] = false;
        }
        if (arr[0] < n) dp[arr[0]] = true;
        for (int i = 0; i < n; i++) {
            dp[i] = dp[i] || (i - arr[i] == 0) || (i - arr[i] - 1 >= 0 && dp[i - arr[i] - 1]);
            if (dp[i - 1] && i + arr[i] < n) {
                dp[i + arr[i]] = true;
            }
        }
        cout << (dp[n - 1] ? "YES" : "NO") << endl;
    }
    return 0;
}
//6
//5 7 8 9 10 3
//