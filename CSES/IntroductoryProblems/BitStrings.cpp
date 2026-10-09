//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

const long long mod = 1000000007;

int main() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}