//
// Created by JMKov on 5/30/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        long long md = 0;
        long long mn = -1000000000;
        for (long long i = 0; i < n; i++) {
            long long d, h;
            cin >> d >> h;
            mn = max(mn, d - h);
            md = max(md, d);
        }
        if (md >= x) {
            cout << 1 << endl;
            continue;
        }
        else if (mn <= 0) {
            cout << -1 << endl;
            continue;
        }
        long long ans = max((long long) 0, (x - md)) / mn + (max((long long) 0, (x - md)) % mn != 0) + 1;
        if (ans <= 0) {
            cout << -1 << endl;
        }
        else {
            cout << ans << endl;
        }
    }
    return 0;
}