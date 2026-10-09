//
// Created by JMKov on 5/17/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
    long long c1 = 1;
    for (long long i = 1; i <= b; i++) {
        c1 = (c1 * ((a - i + 1))) % mod * inv(i) % mod;
        c1 %= mod;
    }
    return c1;
}

void solve() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if (abs(a - b) > 1) {
        cout << 0 << endl;
        return;
    }
    if (a == 0 && b == 0) {
        cout << (c == 0 || d == 0) << endl;
        return;
    }

    long long ans = 0;

//    cout << choose(5, 2) << endl;

    if (a == b) { // m = a, q = c             m = a + 1, q = d
        ans = choose(c + a - 1, a - 1) * choose(d + a, a) % mod
         + choose(c + a, a) * choose(d + a - 1, a - 1) % mod;
        ans %= mod;
    }
    else { // m = max(a, b), q = c                     m = max(a, b), q = d
        long long mx = max(a, b);
        ans = choose(c + mx - 1, mx - 1) * choose(d + mx - 1, mx - 1) % mod;
    }

    cout << ans << endl;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}