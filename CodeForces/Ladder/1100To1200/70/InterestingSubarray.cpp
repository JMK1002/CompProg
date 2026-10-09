//
// Created by JMKov on 3/29/2023.
//
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        bool worked = false;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i < n; i++) {
            if (abs(a[i] - a[i - 1]) >= 2) {
                cout << "YES" << endl;
                cout << i << " " << i + 1 << endl;
                worked = true;
                break;
            }
        }
        if (!worked) {
            cout << "NO" << endl;
        }
    }
    return 0;
}