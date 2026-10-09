//
// Created by JMKov on 7/21/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n;
string s;
string l[300000];
long long dp[300000];

void dfs(long long v, long long d) {
    if (d == 0) {
        dp[v] = 1;
        l[v] = s[v];
        return;
    }
    dfs(v * 2, d - 1);
    dfs(v * 2 + 1, d - 1);

    dp[v] = dp[v * 2] * dp[v * 2 + 1] * ((l[v * 2] != l[v * 2 + 1]) + 1);
    dp[v] %= mod;

    l[v] = s[v] + min(l[v * 2] + l[v * 2 + 1], l[v * 2 + 1] + l[v * 2]);
}

int main() {
    cin >> n >> s;
    s = "x" + s;
    dfs(1, n - 1);
    cout << dp[1] << endl;
    return 0;
}