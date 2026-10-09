//
// Created by JMKov on 7/25/2024.
//
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <map>

using namespace std;

long long n;
long long arr[100005];
long long asdf[5000005];
long long cnt[5000005];
long long dp[5000005];

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        asdf[arr[i]]++;
    }
    for (long long i = 1; i < 5000005; i++) {
        for (long long j = i; j < 5000005; j += i) {
            cnt[i] += asdf[j];
        }
    }
    dp[1] = cnt[1];
    for (long long i = 1; i < 5000005; i++) {
        for (long long j = i; j < 5000005; j += i) {
            dp[j] = max(dp[j], dp[i] + cnt[j] * (j - i));
        }
    }

    long long ans = 0;
    for (long long i = 0; i < n; i++) ans = max(ans, dp[arr[i]]);
    cout << ans << endl;
    return 0;
}