//
// Created by JMKov on 5/29/2024.
//
#include <iostream>
using namespace std;

long long n;
long long arr[200004];
long long inv[200004];
pair<long long, long long> mex[200004];

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        inv[arr[i]] = i;
    }

    mex[1] = {inv[0], inv[0]};
    for (long long i = 2; i <= n; i++) {
        mex[i] = {min(mex[i - 1].first, inv[i - 1]), max(mex[i - 1].second, inv[i - 1])};
    }
    mex[n + 1] = {0, n - 1};
    long long ans = 0;
    for (long long i = 1; i <= n; i++) {
        if (mex[i] == mex[i + 1]) continue;
        else if (inv[i] < mex[i].first) {
            for (long long j = inv[i] + 1; j <= mex[i].first; j++) {
                ans += max((long long) 0, min(j + (i * 2), n) - mex[i].second); // I THINK ITS n AND NOT n - 1
            }
        }
        else {
            for (long long j = inv[i] - 1; j >= mex[i].second; j--) {
                ans += max((long long) 0, mex[i].first - max((long long) -1, j - (i * 2)));
            }
        }
//        cout << ans << endl;
    }
    cout << ans + 1 << endl;
    for (long long i = 0; i <= n + 3; i++) {
        arr[i] = 0;
        inv[i] = 0;
        mex[i] = {0,0};
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