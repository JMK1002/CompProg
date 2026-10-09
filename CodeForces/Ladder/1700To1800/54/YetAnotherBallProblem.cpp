//
// Created by JMKov on 6/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    if (n > k * (k - 1)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    pair<long long, long long> p(1, 1);
    for (long long i = 0; i < min(k * (k - 1), n); i++) {
        if (!(i & 1)) {
            p.second++;
            if (p.second > k) {
                p.first++;
                p.second = p.first + 1;
            }
            cout << p.first << " " << p.second << endl;
        }
        else {
            cout << p.second << " " << p.first << endl;
        }
    }
    return 0;
}