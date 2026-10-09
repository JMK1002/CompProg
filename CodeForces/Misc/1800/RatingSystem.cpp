//
// Created by JMKov on 4/30/2024.
//
#include <iostream>
#include <set>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long arr[n];
    long long pre[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        pre[i] = (i == 0) ? arr[i] : pre[i - 1] + arr[i];
    }
//    for (long long i : pre) cout << i << " ";
//    cout << endl;
    long long val = pre[n - 1];
    long long ans = 0;
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
        mx = max(mx, pre[i]);
        if (mx + pre[n - 1] - pre[i] > val) {
            val = mx + pre[n - 1] - pre[i];
            ans = mx;
        }
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