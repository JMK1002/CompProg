//
// Created by JMKov on 3/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m, k;
        cin >> n >> m >> k;
        int heights[n];
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        bool sad = true;
        for (int i = 0; i < n - 1; i++) {
            m += heights[i] - max(0, heights[i + 1] - k);
            if (m < 0) {
                cout << "NO" << endl;
                sad = false;
                break;
            }
        }
        if (sad) {
            cout << "YES" << endl;
        }
    }
    return 0;
}