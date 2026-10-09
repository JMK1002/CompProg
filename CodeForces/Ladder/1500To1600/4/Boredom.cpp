//
// Created by JMKov on 5/6/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long index[100010];
    long long dp[100010];
    for (int i = 0 ; i < 100010; i++) {
        index[i] = 0;
        dp[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        index[a] += a;
    }
    dp[0] = index[0];
    dp[1] = max(dp[0], index[1]);
//    cout << index[1] << " " << index[2] << endl;
    for (int i = 2; i < 100002; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + index[i]);
    }
    cout << dp[100001] << endl;
    return 0;
}