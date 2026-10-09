//
// Created by JMKov on 5/5/2024.
//

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
    string s;
    cin >> s;
    long long n = s.length();
    reverse(s.begin(), s.end());
    long long dp[5][5][2];
    long long pw[5] = {1, 10, 100, 1000, 10000};
    // currChar, mx, how many changed

    for (int l = 0; l < 5; l++) for (int j = 0; j < 5; j++) for (int k = 0; k < 2; k++) {
        dp[l][j][k] = 0;
    }

    int mx = 0;
    long long prevDp[5][5][2];
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < 5; l++) for (int j = 0; j < 5; j++) for (int k = 0; k < 2; k++) {
            prevDp[l][j][k] = dp[l][j][k];
        }
        for (int l = 0; l < 5; l++) for (int j = 0; j < 5; j++) for (int k = 0; k < 2; k++) {
            dp[l][j][k] = INT32_MIN;
        }

        int c = s[i] - 'A';
        int pc = s[i - 1] - 'A';
        if (i == 0) pc = 0;

        dp[c][max(c, mx)][0] = prevDp[pc][mx][0] + pw[c] * (c >= max(c, mx) ? 1 : -1);

        for (int j = 0; j < 5; j++) {
            dp[j][max(j, mx)][1] = prevDp[pc][mx][0] + pw[j] * (j >= max(j, mx) ? 1 : -1);
        }
        for (int j = 0; j < 5; j++) {
            for (int k = j; k < 5; k++) {
                dp[c][max(c, k)][1] = max(dp[c][max(c, k)][1], prevDp[j][k][1] + pw[c] * (c >= max(c, k) ? 1 : -1));
            }
        }
        mx = max(c, mx);
    }
    long long ans = dp[s[s.size() - 1] - 'A'][mx][0];
    for (int i = 0; i < 5; i++) for (int j = 0; j < 5; j++) ans = max(ans, dp[i][j][1]);
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