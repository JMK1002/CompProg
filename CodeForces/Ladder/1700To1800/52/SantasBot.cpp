//
// Created by JMKov on 6/27/2023.
//
#include <iostream>

#include <algorithm>
using namespace std;

const long long mod = 998244353;

long long inv(long long i) {
    return i <= 1 ? i : mod - (mod/i) * inv(mod % i) % mod;
}

long long presents[1000005];
int cnt[1000005];

int main() {
    int n;
    cin >> n;
//    cout << inv(n) << endl;
//    return 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        for (int j = 0; j < v; j++) {
            int x;
            cin >> x;
            x--;
            cnt[x]++;
            presents[x] += inv(v % mod);
            presents[x] %= mod;
        }
    }
    long long ans = 0;
    long long v = inv(n);
    for (int i = 0; i < 1000000; i++) {
        ans += cnt[i] % mod * presents[i];
        ans %= mod;
//        cout << cnt[i] << " " << presents[i] << endl;
    }
    ans *= v;
    ans %= mod;
    ans *= v;
    ans %= mod;
    cout << ans << endl;
    return 0;
}