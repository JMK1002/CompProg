//
// Created by JMKov on 7/9/2023.
//
#include <iostream>
using namespace std;

long long dp[5002][5002];
const int mod = 998244353;

int main() {
    int r, b, g;
    cin >> r >> b >> g;
    for (int i = 1; i <= 5000; i++) {
        dp[1][i] = i + 1;
        dp[i][1] = i + 1;
    }
    for (int i = 2; i <= 5000; i++) {
        for (int j = 2; j <= 5000; j++) {
            dp[i][j] = j * (dp[i - 1][j - 1]) % mod + dp[i - 1][j];
            dp[i][j] %= mod;
        }
    }
    cout << dp[r][b] * dp[b][g] % mod * dp[r][g] % mod << endl;
    return 0;
}