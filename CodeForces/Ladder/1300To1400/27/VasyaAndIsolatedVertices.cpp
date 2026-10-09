//
// Created by JMKov on 4/10/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << n << " " << n << endl;
        return 0;
    }
    long long mx = 0;
    for (long long i = 1; i * (i - 1) / 2 < m; i++) {
        mx = i;
//        cout << i * (i + 1) /2 << endl;
    }
    mx += (mx * (mx - 1) / 2 != n);
    cout << max((long long) 0, (n - m * 2)) << " " << n - mx << endl;
    return 0;
}