//
// Created by JMKov on 11/18/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

long long mod = 3359232;

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << ((2 * (binpow(2, n / 3, mod))) % mod - 2 + mod) % mod << endl;
    }
    return 0;
}