//
// Created by JMKov on 5/27/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

const long long mod = 1000000007;

long long arr[3002];
long long pw[6002];


int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    pw[0] = 1;
    for (long long i = 1; i < 6002; i++) {
        pw[i] = pw[i - 1] * 2 % mod;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < i; j++) {
            long long l = lower_bound(arr, arr + n, arr[j] - (arr[i] - arr[j])) - arr;
            long long r = (arr + n) - lower_bound(arr, arr + n, arr[i] + (arr[i] - arr[j]));
            ans += pw[l + r];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}