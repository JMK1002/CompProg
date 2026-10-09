//
// Created by JMKov on 5/29/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n;
long long arr[200004];

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
    cin >> n;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        cnt += arr[i];
    }
    long long cnt2 = 0;
    for (long long i = 0; i < n - cnt; i++) {
        cnt2 += arr[i];
    }
    long long num = (n * (n - 1) / 2) % mod;
    long long ans = 0;
    while (cnt2) {
        long long y = inv(cnt2 * cnt2 % mod);
        y %= mod;
        ans += y;
        ans %= mod;
        cnt2--;
    }
    ans *= num;
    ans %= mod;
    cout << ans << endl;

    for (int i = 0; i < n; i++) arr[i] = 0;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}