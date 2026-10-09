//
// Created by JMKov on 4/25/2024.
//
#include <iostream>
using namespace std;

long long n, k;
long long arr[200002];

void solve() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long za = 0;
    long long ans = 1;
    for (long long i = 0; i < k; i++) {
        while (za < n && arr[za] <= ans + za) {
            za++;
        }
        ans += za;
    }
    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}