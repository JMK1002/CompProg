//
// Created by JMKov on 7/14/2024.
//
#include <iostream>
using namespace std;

long long n, k;
long long arr[300005];
long long times[300005][2];
long long pre[300005];
long long dp[300005][2];
long long last[300005];


void solve() {
    cin >> n >> k;
    arr[0] = -9234867;
    for (long long i = 1; i <= n; i++) cin >> arr[i];
    for (long long i = 0; i < 2; i++) for (long long j = 1; j <= k; j++) cin >> times[j][i];

    for (long long i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + times[arr[i]][arr[i - 1] == arr[i]];
    }
    for (long long i = 1; i <= k; i++) last[i] = -1;
    for (long long i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]) + times[arr[i]][0];
        if (last[arr[i]] != -1) {
            long long lst = last[arr[i]];
            dp[i][1] = min(dp[min(i - 1, lst + 1)][0], dp[min(i - 1, lst + 1)][1]) + max((long long) 0, pre[i - 1] - pre[lst + 1]) + times[arr[i]][1];
        }
        else {
            dp[i][1] = INT64_MAX;
        }
        last[arr[i]] = i;
    }
    cout << min(dp[n][0], dp[n][1]) << endl;

    for (long long i = 0; i <= n; i++) {
        last[max((long long) 0, arr[i])] = 0;
        pre[i] = 0;
        dp[i][0] = 0;
        dp[i][0] = 0;
        arr[i] = 0;
    }
    for (long long i = 0; i <= k; i++) {
        times[i][0] = 0;
        times[i][1] = 0;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}