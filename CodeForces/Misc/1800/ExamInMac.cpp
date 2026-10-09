//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

long long arr[300001];

void solve() {
    long long n, c;
    cin >> n >> c;
    long long e = 0, o = 0;
    long long exclude = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        e += (arr[i] % 2 == 0);
        o += (arr[i] % 2 == 1);
        exclude += (arr[i] & 1) ? (2 * c - arr[i] + 1) / 2 : (2 * c - arr[i] + 2) / 2;
    }
    exclude -= e * (e - 1) / 2 + o * (o - 1) / 2;
//    cout << (c * (c + 3) / 2) + 1 << " " << exclude << endl;
    cout << (c * (c + 3) / 2 + 1 - exclude) << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}