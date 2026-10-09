//
// Created by JMKov on 6/27/2024.
//
#include <iostream>
using namespace std;

const int mod = 998244353;

int pow[200004];
int choose[200004];

int inv(int a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main() {
    int n, k;
    cin >> n >> k;
    pow[0] = 1;
    choose[k + 1] = 1;
    for (int i = 1; i < 200004; i++) pow[i] = (pow[i - 1] * 2) % mod;
    for (int i = k + 1; i < 200003; i++) {
        choose[i + 1] = choose[i] * (i + 1) * inv(i - k);
        choose[i + 1] %= mod;
    }

    int ans = 0;
    for (int i = k; i < n; i++) {
        ans += (n - k) * (pow[i - 1] - choose[i + 1]) % mod;
        ans %= mod;
    }
    cout << 1 + ans << endl;
    return 0;
}