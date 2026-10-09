//
// Created by JMKov on 7/5/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, k;
    cin >> n >> k;
    long long asdf = 1;
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        asdf = asdf * v / __gcd(asdf, v);
        asdf %= k;
        if (asdf == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}