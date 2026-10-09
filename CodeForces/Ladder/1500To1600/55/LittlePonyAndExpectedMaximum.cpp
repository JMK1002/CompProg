//
// Created by JMKov on 5/22/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    double ans = m;
    for (int i = m - 1; i >= 0; i--) {
        ans -= pow(((double) i / m), n);
    }
    cout.precision(20);
    cout << ans << endl;
    return 0;
}
// m * m^n - Ei^n)/m^n