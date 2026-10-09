//
// Created by JMKov on 4/16/2024.
//
#include <iostream>
using namespace std;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << d / 2 + a / 2 + b / 2 + c / 2 + (a != 0 && b != 0 && c != 0 && a % 2 + b % 2 + c % 2 == 3) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}