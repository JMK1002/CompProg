//
// Created by JMKov on 8/4/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long k, n;
long long arr[200005];
long long md[200005];
long long exists[400005];

void clean() {
    for (long long i = 0; i <= n; i++) {
        exists[md[i]] = 0;
        arr[i] = 0;
        md[i] = 0;
    }
}

void solve() {
    cin >> n >> k;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        md[i] = arr[i] % (2 * k);
        exists[md[i]]++;
    }
    sort(arr, arr + n);
    sort(md, md + n);
    for (long long i = 0; i < n; i++) {
        if (exists[(md[i] + k) % (2 * k)]) {
            cout << -1 << endl;
            clean();
            return;
        }
    }
    long long v = arr[n - 1] % (2 * k);
    long long cnt = 0;
    for (long long i = 0; i < k; i++) {
        cnt += (exists[(v - i + 2 * k) % (2 * k)]);
    }
    if (cnt == n) {
        cout << arr[n - 1] << endl;
        clean();
        return;
    }
    for (long long i = 1; i < 2 * k; i++) {
        cnt += (exists[(v + i) % (2 * k)]);
        cnt -= (exists[(v + i + k) % (2 * k)]);
        if (cnt == n) {
            cout << arr[n - 1] + i << endl;
            clean();
            return;
        }
    }
    cout << -1 << endl;
    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}