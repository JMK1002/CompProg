//
// Created by JMKov on 5/8/2023.
//
#include <iostream>
using namespace std;

int main() {
    cout.precision(10);
    int n;
    double m;
    cin >> n >> m;
    double x = m;
    for (int i = 0; i < n * 2; i++) {
        int a;
        cin >> a;
        if (a == 1) {
            cout << -1 << endl;
            return 0;
        }
        x *= a;
        x /= (a - 1);
    }
    x -= m;
    cout << x << endl;
    return 0;
}