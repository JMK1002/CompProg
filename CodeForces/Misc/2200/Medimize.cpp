//
// Created by JMKov on 9/13/2024.
//
#include <iostream>
using namespace std;

long long n, k;
long long arr[500005];
long long b[500005];
long long dp[500005];

void solve() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) cin >> arr[i];

    long long low = 0;
    long long high = 1000000001;
    while (high - low > 1) {
        long long a = (low + high) / 2;
        for (long long i = 0; i < n; i++) b[i] = (arr[i] > a ? 1 : -1);
        for (long long i = 0; i < n; i++) {
            if (i == 0) dp[i] = b[i];
            else if (i % k == 0) dp[i] = max(dp[i - k], b[i]);
            else {
                if (i >= k) dp[i] = max(dp[i - k], dp[i - 1] + b[i]);
                else dp[i] = dp[i - 1] + b[i];
            }
        }
        long long ans = dp[n - 1];
//        cout << ans << endl;

        if (ans > 0) {
            low = a;
        }
        else {
            high = a;
        }
    }
    cout << low + 1 << endl;

    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        b[i] = 0;
        dp[i] = 0;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}