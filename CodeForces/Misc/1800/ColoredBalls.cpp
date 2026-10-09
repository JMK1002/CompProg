//
// Created by JMKov on 4/16/2024.
//
#include <iostream>
using namespace std;

long long dp[5010];
const long long mod = 998244353;

long long m(long long v) {
    v += (v / mod + 1) * mod;
    v %= mod;
    return v;
}

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long j = 0; j < n; j++) {
        for (long long i = 5000 - arr[j]; i >= 0; i--) {
            dp[i + arr[j]] += dp[i];
            dp[i + arr[j]] = m(dp[i + arr[j]]);
        }
        dp[arr[j]]++;
        dp[arr[j]] = m(dp[arr[j]]);
    }
    dp[0] = 1;
    long long ans = 0;
    for (long long i = 0; i < 5001; i++) {
        ans += m(dp[i] * ((i + 1) / 2));
        ans = m(ans);
    }
//    cout << ans << endl;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < arr[i]; j++) {
            ans += m(arr[i] * dp[j]) - m((arr[i] + j + 1) / 2 * dp[j]);
            ans = m(ans);
        }
    }
    cout << ans << endl;
}