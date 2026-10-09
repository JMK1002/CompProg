//
// Created by JMKov on 6/24/2024.
//
#include <iostream>
using namespace std;

long long n;
string s;
long long dp[1000010];

void solve() {
    cin >> n >> s;
    for (long long i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            dp[i] = dp[i + 1];
        }
        else {
            dp[i] = dp[i + 3] + n - i;
        }
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        ans += dp[i];
        dp[i] = 0;
    }
    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 0 1 2 3 4 5 6 7 8 9
// 0 1 1 1 2 2 3 3
// 0 1 2 3 5 7 10 13

//