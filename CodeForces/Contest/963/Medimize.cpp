//
// Created by JMKov on 8/4/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;
long long arr[500005];
long long srtd[500005];
pair<long long, long long> dp[1000005];

void clean() {
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        srtd[i] = 0;
        dp[i + k] = {0, 0};
    }
}

void solve() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        srtd[i] = arr[i];
    }
    sort(srtd, srtd + n);

    if (k == 1) {
        cout << srtd[n - 1] << endl;
        clean();
        return;
    }
    if (n <= k) {
        cout << srtd[n - ((n - 1) % k + 1 + 2) / 2] << endl;
        clean();
        return;
    }
    long long low = 0;
    long long high = n;
    while (high - low > 1) {
        long long mid = (low + high) / 2;
        long long disp = n - mid;
        for (long long i = k; i < n + k; i++) {
            if (arr[i - k] == srtd[n - disp]) {
                dp[i] = {dp[i - 1].first + 1, dp[i - 1].second - 1};
            } else if (arr[i - k] > srtd[n - disp]) {
                dp[i] = {dp[i - 1].first + 1, dp[i - 1].second};
            }
            dp[i] = max(dp[i], dp[i - k]);
        }

        long long amnt = 0;
        for (long long i = n - disp; i < n; i++) {
            if (srtd[n - disp] == srtd[i]) amnt++;
            else break;
        }
        if (dp[n + k - 1].first >= ((n - 1) % k + 1 + 2) / 2) {
            low = mid;
        } else {
            high = mid;
        }
        for (long long i = k; i < n + k; i++) dp[i] = {0,0};
    }
    cout << srtd[low] << endl;
    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}