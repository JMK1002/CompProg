//
// Created by JMKov on 5/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int64_t n, k; cin >> n >> k;
        if (n < k) {
            cout << "NO\n";
        } else if (n == k) {
            cout << "YES\n1\n1\n";
        } else if (n < 2 * k - 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n2\n" << n - k + 1 << " 1\n";
        }
    }
}