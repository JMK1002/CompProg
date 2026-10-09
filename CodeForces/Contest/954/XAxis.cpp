//
// Created by JMKov on 6/23/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans = 10000;
        for (int i = 0; i <= 11; i++) {
            ans = min(ans, abs(a - i) + abs(b - i) + abs(c - i));
        }
        cout << ans << endl;
    }
}