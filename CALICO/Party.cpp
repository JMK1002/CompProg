//
// Created by JMKov on 11/18/2023.
//
#include <iostream>
using namespace std;

long long dp[100003];

int main() {
    long long t;
    cin >> t;
    dp[1] = 0;
    for (long long i = 2; i < 100003; i++) {
        dp[i] = dp[i - 1] + (i - 1) + i * i - i;
    }
    while (t--) {
        long long n;
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}