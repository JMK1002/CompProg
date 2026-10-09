//
// Created by JMKov on 6/9/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
        double bofaDeezNuts;
        cin >> bofaDeezNuts;
    }
    int dp[n];
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[i] >= arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
//    cout << endl;
    int ans = 0;
    for (int i : dp) {
//        cout << i << " ";
        ans = max(i, ans);
    }
//    cout << endl;
    cout << n - ans << endl;
    return 0;
}