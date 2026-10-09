//
// Created by JMKov on 4/17/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

const long long INF = INT64_MAX;

long long n;
long long arr[300003];
long long pre[300003];

vector<long long> solve() {
    vector<long long> dp(n);
    pre[n - 1] = arr[n - 1];
    for (long long i = n - 2; i >= 0; i--) pre[i] = pre[i + 1] + arr[i];

    bool same = true;
    dp[0] = INF;

    int h = 0;
    for (long long i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            dp[i] = 1;
            same = false;
            if (arr[i] != arr[i - 1]) h = i;
            continue;
        }
        long long low = 0;
        long long high = h;
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (pre[mid] - pre[i] <= arr[i]) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        dp[i] = (pre[low] - pre[i] <= arr[i] || h == 0) ? INF : i - low;
        if (arr[i] != arr[i - 1]) h = i;
    }

    return dp;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (long long i = 0; i < n; i++) cin >> arr[i];

        vector<long long> dp1 = solve();
        reverse(arr, arr + n);
        vector<long long> dp2 = solve();
        reverse(dp2.begin(), dp2.end());


//        for (long long i = 0; i < n; i++) cout << dp1[i] << " ";
//        cout << endl;
//        for (long long i = 0; i < n; i++) cout << dp2[i] << " ";
//        cout << endl;

        for (long long i = 0; i < n; i++) cout << ((min(dp1[i], dp2[i]) == INF) ? -1 : min(dp1[i], dp2[i])) << " ";
        cout << endl;
    }
    return 0;
}