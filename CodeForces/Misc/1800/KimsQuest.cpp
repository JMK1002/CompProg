//
// Created by JMKov on 4/19/2024.
//
#include <iostream>
using namespace std;

const long long mod = 998244353;

long long binpow(long long a, long long b) {
    long long v = a;
    long long ret = 1;
    while (b > 0) {
        if (b & 1) ret *= v;
        v *= v;
        v %= mod;
        ret %= mod;
        b /= 2;
    }
    return ret;
}

long long cor(long long a) {
    while (a < 0) a += mod;
    return a % mod;
}

int main() {
    long long n;
    cin >> n;
    long long arr[n];
    long long ec = 0;
    long long oc = 0;
    long long e = 0;
    long long o1 = 0;
    long long o2 = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] & 1) {
            o2 += o1 + 1;
            o1 += e + 1;
        }
        else e += o2 + 1;
        o2 %= mod;
        o1 %= mod;
        e %= mod;

        ec += !(arr[i] & 1);
        oc += (arr[i] & 1);
    }
    cout << cor(e + o1 + o2 - ec * oc % mod - oc * (oc - 1) / 2 % mod - ec - oc * 2 + binpow(2, ec) - ec * (ec - 1) / 2 % mod - ec - 1);

    return 0;
}