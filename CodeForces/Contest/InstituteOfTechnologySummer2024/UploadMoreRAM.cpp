//
// Created by JMKov on 6/30/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        cout << (n - 1) * k + 1 << endl;
    }
    return 0;
}