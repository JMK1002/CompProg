//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100004];
long long d[200004];

void solve() {
    long long low = 1000000000000000000;
    long long n, m, k;
    cin >> n >> m >> k;
    pair<long long, long long> diff[n - 1];
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 1; i < n; i++) diff[i - 1] = {arr[i] - arr[i - 1], i - 1};

    sort(diff, diff + (n - 1));

    for (long long i = 0; i < m; i++) cin >> d[i];
    sort(d, d + m);

    for (long long i = 0; i < k; i++) {
        long long x;
        cin >> x;
        if (n == 1) continue;
        long long ind = distance(d, lower_bound(d, d + m, (double) (arr[diff[n - 2].second] + arr[diff[n - 2].second + 1]) / 2 - x + 1));
//        cout << ind << endl;
        if (ind < m) low = min(low, max(d[ind] + x - arr[diff[n - 2].second], arr[diff[n - 2].second + 1] - d[ind] - x));
        ind--;
        if (ind < m && ind >= 0) low = min(low, max(d[ind] + x - arr[diff[n - 2].second], arr[diff[n - 2].second + 1] - d[ind] - x));
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    long long next = (n - 3 < 0) ? 0 : diff[n - 3].first;
    cout << max(min(low, diff[n - 2].first), next) << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}