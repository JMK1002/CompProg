//
// Created by JMKov on 6/1/2024.
//
#include <iostream>
#include <set>

using namespace std;

const long long mod = 998244353;
long long diff[300004];
long long pre[300004];
long long ck[300004];
set<long long> inds;
long long diams = 0;

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long binpow(long long a, long long b) {
    long long ret = 1;
    while (b) {
        if (b & 1) ret *= a;
        a *= a;
        a %= mod;
        ret %= mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) cin >> diff[i];
    for (long long i = 1; i <= n; i++) pre[i] = pre[i - 1] + diff[i - 1];
    for (long long i = 0; i <= n; i++) inds.insert(pre[i]);
    for (long long i = 0; i < n; i++) {
        diams += (inds.find(pre[i] + pre[n] / 2) != inds.end() || inds.find(pre[i] - pre[n] / 2) != inds.end());
    }
//    cout << pre[n] << endl;
    diams /= 2;
    if (pre[n] % 2 == 1) diams = 0;
//    cout << diams << endl;

    ck[0] = 1;
    for (long long i = 1; i <= diams; i++) {
        ck[i] = ck[i - 1] * ((diams - i + 1) * inv(i) % mod);
        ck[i] %= mod;
//        cout << ck[i] << " ";
    }
//    cout << endl;

    long long ans = 0;
    long long run = 1;
    for (long long i = 0; i <= diams; i++) {
        if (i < diams && m - i - 1 <= 0) continue;

        long long bit = 1;
        bit *= binpow((m - i) * (m - 1 - i) % mod, diams - i);
        bit %= mod;
        bit *= binpow(m - i, n - 2 * diams);
        bit %= mod;
        bit *= run;
        bit %= mod;
        bit *= ck[i];
        bit %= mod;
        ans += bit;
        ans %= mod;
        run *= m - i;
        run %= mod;
//        cout << bit << endl;
    }
    cout << ans << endl;
    return 0;
}