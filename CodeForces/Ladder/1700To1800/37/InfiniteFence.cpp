//
// Created by JMKov on 6/21/2023.
//
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, b, k;
        cin >> r >> b >> k;
        if (k == 1) {
            cout << "REBEL" << endl;
            continue;
        }
        if (r == b) {
            cout << "OBEY" << endl;
            continue;
        }
        int v = r;
        r = max(r, b);
        b = min(v, b);
        int gcd = __gcd(r, b);
        int end = (r - gcd) / b * b + gcd;
        end -= b * (end == r);
//            cout << end / b + 1 - (end % b == 0) << " " << end << " " << modr << endl;
        if (end / b + 1 - (end % b == 0) >= k) {
            cout << "REBEL" << endl;
            continue;
        }
        cout << "OBEY" << endl;
//        cout << diff << endl;
    }
    return 0;
}