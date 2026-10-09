//
// Created by JMKov on 7/15/2023.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long btwn(long long n, long long s) {
    long long ans = n % 10;
    long long c = 10;
    while (n) {
        n /= 10;
        if (s > 0) c *= 10;
        s--;
        ans += c * (n % 10);
        c *= 10;
    }
    return ans;
}

long long sz(long long n) {
    long long ans = 0;
    while (n) {
        n /= 10;
        ans++;
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    long long sizes[11];
    for (long long & size : sizes) size = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        sizes[sz(arr[i])]++;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < 11; j++) {
            ans += btwn(arr[i], j) % mod * sizes[j];
            ans %= mod;
            ans += btwn(arr[i], j - 1) % mod * sizes[j] * 10;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}