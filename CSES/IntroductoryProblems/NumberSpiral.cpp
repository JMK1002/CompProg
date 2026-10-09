//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        long long ans = (max(x, y) - 1);
        ans *= ans;
        long long dist;
        if (x > y) dist = y;
        else dist = (max(x, y) * 2) - x;

        if (max(x, y) % 2 == 1) ans += dist;
        else ans += (max(x, y) * 2) - dist;
        cout << ans << endl;
    }
    return 0;
}