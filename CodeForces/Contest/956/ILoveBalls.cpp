//
// Created by JMKov on 7/7/2024.
//
#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long n, k;
long long arr[400005];

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
    long long res = 1;
    for (long long i = a; i >= 1; i--) {
        res *= i;
        res %= mod;
    }
    for (long long i = b; i >= 1; i--) {
        res *= inv(i);
        res %= mod;
    }
    for (long long i = a - b; i >= 1; i--) {
        res *= inv(i);
        res %= mod;
    }
    return res;
}

void solve() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long ans1 = 0;
    long long ans2 = 0;
    long long s = 0;
    for (long long i = 0; i < k; i++) {
        s += arr[i];
        s %= mod;
    }
    long long asdf = (n - k + 1) / 2 % mod * inv(n - k + 1) % mod * s % mod;
    ans2 += asdf % mod;
    ans1 += (s - asdf + mod) % mod;
    long long amnt = choose(n - k - 1, (n - k - 1) / 2);
    amnt %= mod;
    s = 0;
    for (long long i = k; i < n; i++) {
        s += arr[i];
        s %= mod;
    }
    long long l = s * amnt % mod * inv(choose(n - k, (n - k) / 2)) % mod;
    ans1 += l % mod;
    ans2 += (s - l + mod) % mod;
    ans1 %= mod;
    ans2 %= mod;
    cout << ans1 << " " << ans2 << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
}