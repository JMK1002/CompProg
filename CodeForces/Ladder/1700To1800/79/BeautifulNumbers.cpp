//
// Created by JMKov on 7/8/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int mod = 1000000007;

bool good(int v, int a, int b) {
    while (v) {
        if (v % 10 != a && v % 10 != b) return false;
        v /= 10;
    }
    return true;
}

int inv(int i) {
    return i <= 1 ? i : mod - (long long)(mod/i) * inv(mod % i) % mod;
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> arr;
    int s = b * n;
    for (int i = 0; i <= n; i++) {
        if (good(s, a, b)) arr.push_back(i);
        s -= b - a;
    }
    long long choose[n + 1];
    long long v = 1;
    for (int i = 0; i <= n; i++) {
        choose[i] = v;
        v *= (n - i);
        v %= mod;
        v *= inv((i + 1));
        v %= mod;
//        cout << choose[i] << " ";
    }
//    cout << endl;
    choose[n] = 1;
    long long ans = 0;
    for (int i : arr) {
        ans += choose[i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}