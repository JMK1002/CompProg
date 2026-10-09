//
// Created by JMKov on 6/30/2024.
//
#include <iostream>
using namespace std;

long long arr[100004];
long long amnt[100004];

void solve() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long ans = 0;
    long long mx = 0;
    long long run = arr[0];
    for (long long i = 1; i < n; i++) {
        run = max(run, arr[i]);
        amnt[i] = run - arr[i];
        mx = max(mx, amnt[i]);
        ans += amnt[i];
    }
    cout << ans + mx << endl;
    for (long long i = 0; i <= n; i++) {
        arr[i] = 0;
        amnt[i] = 0;
    }
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}