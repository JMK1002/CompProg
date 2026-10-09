//
// Created by JMKov on 7/16/2024.
//
#include <iostream>
#include <unordered_set>
#include <vector>
#include <set>

using namespace std;

long long n;

void solve() {
    cin >> n;
    long long mn = 0;
    long long mx = 0;
    long long curr = 0;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        curr += x;
        mn = min(mn, curr);
        mx = max(mx, curr);
    }
    cout << mx - mn << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}