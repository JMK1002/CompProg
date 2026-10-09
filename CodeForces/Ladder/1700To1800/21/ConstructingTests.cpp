//
// Created by JMKov on 6/13/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        bool hasAns = false;
        if (x == 0) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        for (int i = 1; i < 40000 && 2 * i < (i * i + x) && (i * i + x) < 2e9; i++) {
            int v = i * i + x;
            int n1 = sqrt(v);
            if (pow(n1, 2) == v) {
                int m;
                for (m = 1; n1 / m >= i; m++) {
//                    cout << m << endl;
                    if (n1 / m == i) {
                        cout << n1 << " " << (m) << endl;
                        hasAns = true;
                        break;
                    }
                }
                if (hasAns) break;
            }
        }
        if (hasAns) continue;
        cout << -1 << endl;
    }
    return 0;
}