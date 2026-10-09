//
// Created by JMKov on 6/24/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, t;
    double p;
    cin >> n >> p >> t;
    if (p == 1) {
        cout << min(t, n) << endl;
        return 0;
    }
    double ans = 0;
    double choose = 1;
    cout.precision(20);
    for (int i = 0; i < t; i++) {
        ans *= 1 - p;
        choose *= (double) (t - i) / (i + 1);
        choose *= p;
        ans += choose * min(n, i + 1);
        cout << choose << " " << ans << endl;
//        ans += choose;
    }
    cout << ans << endl;
    return 0;
}