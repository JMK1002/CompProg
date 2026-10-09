//
// Created by JMKov on 6/9/2024.
//
#include <iostream>
using namespace std;

long long n;
long long arr[400005];
long long dp[400005][2];
long long mx[400005][2];

long long conv(long long a, long long b) {
    return (b) ? 2 * n - a - 1 : a;
}

long long calc(long long a, long long b, long long t) {
    return max(arr[conv(a, 1 - b)] + 1, t + max((long long) 0, mx[n - 1 - a][b] - (t - a)) + (n - 1 - a) * 2 + 1);
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 2 * n - 1; i >= n; i--) cin >> arr[i];

    for (long long i = 0; i < 2 * n ; i++) {
        dp[i][0] = arr[i] - i + 1;
        dp[i][1] = arr[i] - (2 * n - 1 - i) + 1;
    }
    mx[0][0] = 0;
    mx[0][1] = 0;
    for (long long i = 1; i < n; i++) {
        mx[i][0] = max(mx[i - 1][0], max(dp[n + i - 1][0], dp[n - i][0]));
        mx[i][1] = max(mx[i - 1][1], max(dp[n + i - 1][1], dp[n - i][1]));
    }

    long long ans = INT64_MAX;
    long long currTime = 0;
    for (long long i = 0; i < n; i++) {
        if (i % 2 == 0) {
//            cout << calc(i, 0, currTime) << " " << currTime << endl;
            ans = min(ans, calc(i, 0, currTime));
            currTime = max(max(currTime + 1, arr[conv(i, 1)] + 1) + 1, arr[conv(i + 1, 1)] + 1);
        }
        else {
//            cout << calc(i, 1, currTime) << " " << currTime << endl;
            ans = min(ans, calc(i, 1, currTime));
            currTime = max(max(currTime + 1, arr[conv(i, 0)] + 1) + 1, arr[conv(i + 1, 0)] + 1);
        }
    }
    ans = min(ans, currTime);
    cout << ans << endl;

    for (long long i = 0; i <= 2 * n; i++) {
        arr[i] = 0;
        dp[i][0] = 0;
        dp[i][1] = 0;
        mx[i][0] = 0;
        mx[i][1] = 0;
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}