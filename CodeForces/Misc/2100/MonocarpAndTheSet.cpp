//
// Created by JMKov on 7/4/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, m;
string s;

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
    cin >> n >> m >> s;
    long long ans = 1;
    for (long long i = 1; i < n - 1; i++) {
        if (s[i] == '?') {
            ans *= (i);
            ans %= mod;
        }
    }
    if (s[0] == '?') cout << 0 << endl;
    else cout << ans << endl;
    while (m--) {
        long long a;
        char c;
        cin >> a >> c;
        a--;

        if (s[a] == '?' && a != 0) {
            ans *= inv(a);
            ans %= mod;
        }
        if (c == '?' && a != 0) {
            ans *= (a);
            ans %= mod;
        }

        s[a] = c;
        if (s[0] == '?') cout << 0 << endl;
        else cout << ans << endl;
    }
}

int main() {
    long long t;
//    cin >> t;
    t=1;
    while (t--) {
        solve();
    }
    return 0;
}