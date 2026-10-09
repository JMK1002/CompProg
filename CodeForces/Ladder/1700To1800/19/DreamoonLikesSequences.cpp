//
// Created by JMKov on 6/12/2023.
//
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int d, m;
        cin >> d >> m;
        vector<long long> bruh(3);
        bruh[0] = 1;
        bruh[1] = 3;
        bruh[2] = 11;
        if (d == 1) {
            cout << 1 % m << endl;
        } else if (d == 2) {
            cout << 3 % m << endl;
        } else if (d == 3) {
            cout << 5 % m << endl;
        } else if (d == 4) {
            cout << 11 % m << endl;
        }
        if (d <= 4) {
            continue;
        }
        long long diff = 6 % m;
        int count = 0;
        int val = 1;
        while (val <= d) {
            val = val << 1;
            count++;
        }
        for (int i = 3; i < count; i++) {
            diff = (((1 << i) - (1 << (i - 1)) - 1) * diff + bruh[i - 1]) + 1;
            diff %= m;
            bruh.push_back((diff * 2 - 1) % m);

        }
        long long ans = bruh[bruh.size() - 1] + diff * ((d - (1 << (bruh.size() - 1))) % m);
        ans %= m;
        while (ans < 0) ans += m;
        cout << ans << endl;
//    for (int i = 0; i < 32; i++) cout << bruh[i] << endl;
    }
    return 0;
}