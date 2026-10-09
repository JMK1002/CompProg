//
// Created by JMKov on 5/26/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << (((n - m) % 2 == 0 && n >= m) ? "YES" : "NO") << endl;
    }
    return 0;
}