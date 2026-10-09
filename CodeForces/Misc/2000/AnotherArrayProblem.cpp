//
// Created by JMKov on 5/28/2024.
//
#include <iostream>
using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long arr[n];
    long long sum = 0;
    long long mx = 0;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        mx = max(arr[i], mx);
    }

    if (n == 2) {
        cout << max(sum, 2 * abs(arr[0] - arr[1])) << endl;
    }
    else if (n == 3) {
        cout << max(sum, 3 * max(max(arr[0], arr[2]), max(abs(arr[0] - arr[1]), abs(arr[2] - arr[1])))) << endl;
    }
    else {
        cout << max(sum, mx * n) << endl;
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