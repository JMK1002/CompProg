//
// Created by JMKov on 4/21/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

bool comp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

void solve() {
    long long n, k;
    cin >> n;
    long long arr[n];
    long long ans[n];
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = 0;
    }
    cin >> k;

    if (n != 1) for (long long i = n - 2; i >= 0; i--) arr[i] = min(arr[i + 1], arr[i]);
    long long prev = INT64_MAX;
    for (long long i = 0; i < n; i++) {
        long long diff = arr[i] - (i - 1 >= 0 ? arr[i - 1] : 0);
        if (diff) {
            prev = min(prev, k / diff);
            k -= diff * prev;
        }
        cout << prev << " ";
    }
    cout << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}