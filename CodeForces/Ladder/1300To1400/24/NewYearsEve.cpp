//
// Created by JMKov on 4/9/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (k == 1 || n == 1) {
        cout << n << endl;
        return 0;
    }

    long long ans = 1;
    for (long long i = 1; i <= n; i *= 2) {
        ans = i;
    }
    ans *= 2;
    cout << (ans - 1) << endl;
    return 0;
}