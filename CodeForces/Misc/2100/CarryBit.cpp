//
// Created by JMKov on 7/18/2024.
//
#include <iostream>
using namespace std;

const long long mod = 1000000007;

long long n;
long long k;
long long cnt[1000004];
long long ch[1000004];
long long ch2[1000004];

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long binpow(long long a, long long b) {
    if (b < 0) return 0;
    long long ret = 1;
    long long run = a;
    while (b != 0) {
        if (b & 1) {
            ret *= run;
            ret %= mod;
        }
        run *= run;
        run %= mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    cin >> n;
    cin >> k;
    if (k == 0) {
        cout << binpow(3, n) << endl;
        return 0;
    }

//    for (long long i = 0; i < (1 << n); i++) {
//        for (long long j = 0; j < (1 << n); j++) {
//            cnt[__builtin_popcount(i) + __builtin_popcount(j) - __builtin_popcount(i + j)]++;
//        }
//    }


    ch[0] = 1;
    ch2[1] = 1;
    for (long long i = 1; i <= n - k; i++) {
        ch[i] = ch[i - 1] * (n - k - i + 1) % mod * inv(i) % mod;
    }
    for (long long i = 2; i <= n; i++) {
        ch2[i] = ch2[i - 1] * (k - i + 1) % mod * inv(i - 1) % mod;
    }

    long long ans = 0;
    for (long long i = 1; i <= k; i++) {
        ans += ch2[i] * ch[i] % mod * binpow(3, (n - i * 2)) * (k + i <= n) % mod;
        ans %= mod;
        ans += ch2[i] * ch[max((long long) 0, i - 1)] % mod * binpow(3, (n - i * 2 + 1)) * (k + i <= n + 1) % mod;
        ans %= mod;
    }
    cout << ans << endl;
//        cout << ans << " " << cnt[k] << endl;
    return 0;
}