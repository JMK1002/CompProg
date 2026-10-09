//
// Created by JMKov on 6/21/2024.
//
#include <iostream>
using namespace std;

int n, k;

void solve() {
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n / k * k; i++) {
        cnt = i / k;
        if (i < k / 2 + cnt * k) cout << (k / 2 - (i - cnt * k)) + cnt * k << " ";
        else cout << (k - ((i - cnt * k) - k / 2)) + cnt * k << " ";
    }
    for (int i = n / k * k; i < n; i++) {
        int md = (n + n / k * k) / 2;
        if (i < md) cout << (md - (i - n / k * k)) << " ";
        else cout << (n - (i - md)) << " ";
    }
    cout << endl;
    cout << (n / k + 1 - (n % k == 0)) << endl;
    for (int i = 0; i < n; i++) {
        cout << 1 + (i / (k)) << " ";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}