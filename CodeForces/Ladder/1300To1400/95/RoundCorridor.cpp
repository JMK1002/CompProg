//
// Created by JMKov on 5/3/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long n, m;
    int q;
    cin >> n >> m >> q;
    long long gcd = __gcd(m, n);

    while (q--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long i1 = (x1 == 1) ? (y1 - 1) / (n / gcd) : (y1 - 1) / (m / gcd);
        long long i2 = (x2 == 1) ? (y2 - 1) / (n / gcd) : (y2 - 1) / (m / gcd);
            cout << ((i1 == i2) ? "YES" : "NO") << endl;
    }
    return 0;
}