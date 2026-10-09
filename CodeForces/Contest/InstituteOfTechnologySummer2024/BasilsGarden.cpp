//
// Created by JMKov on 6/30/2024.
//
#include <iostream>
using namespace std;

long long n;
long long arr[100004];

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long time = 0;
    for (long long i = n - 1; i >= 1; i--) {
        time += arr[i];
        arr[i - 1] = max((long long) 1, arr[i - 1] - time);
    }
    time += arr[0];
    cout << time << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// 1 2 8 2 3 4 2 1
// 1 2 1000 2 3 0
// 9 8 7 6 5 4
// 9

// 1 2 8 2 3 3 1 0
// 1 2 7 2 3 2 0 0
// 1 2 6 2 2 1 0 0
// 1 2 5 2 1 0 0 0
// 1 2 4 1 0 0 0 0
// 1 2 3 0 0 0 0 0
// 1 2 2 0 0 0 0 0
// 1 2 1 0 0 0 0 0
// 1 1 0 0 0 0 0 0
// 1 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0