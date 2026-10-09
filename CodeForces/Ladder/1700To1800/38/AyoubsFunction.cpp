//
// Created by JMKov on 6/21/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;
        long long ans = ((n - m) / (m + 1) + 1) * ((n - m) / (m + 1) + 2) / 2 * ((n - m) % (m + 1)) +
                  ((n - m) / (m + 1)) * ((n - m) / (m + 1) + 1) / 2 * ((m + 1) - (n - m) % (m + 1));
//        cout << ((n - m) / (m + 1) + 1) * ((n - m) / (m + 1) + 2) / 2 * ((n - m) % (m + 1)) << endl;
//        cout << ((n - m) / (m + 1)) * ((n - m) / (m + 1) + 1) / 2 * ((m + 1) - (n - m) % (m + 1)) << endl;
        cout << n * (n + 1) / 2 - ans << endl;
//        cout << endl;
    }
    return 0;
}