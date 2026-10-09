//
// Created by JMKov on 4/19/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = INT32_MAX;

int n;
int arr[100004];

int check(bool rev) {
    int ind = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[(i + 1) % n]) {
            ind = i + 1;
        }
    }
    bool worked = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[(i + ind) % n] > arr[(i + ind + 1) % n]) {
            worked = false;
            break;
        }
    }
    if (!worked) return INF;
    if (ind == 0) return rev;
    return min(n - ind + rev, 2 + ind - rev);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = check(false);
    reverse(arr, arr + n);
    ans = min(check(true), ans);
    if (ans == INF) ans = -1;
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}