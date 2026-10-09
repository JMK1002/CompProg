//
// Created by JMKov on 3/2/2024.
//
#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        if (k >= 4 * n - 4) {
            cout << ((2 * n - 2) + k - (4 * n - 4)) << endl;
            continue;
        }
        cout << ((k + 1) / 2) << endl;
    }
    return 0;
}