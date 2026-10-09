//
// Created by JMKov on 6/27/2024.
//
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

pair<long long, long long> arr[1000004];
long long thing[1000004];
long long dp[1000004];

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < 1000004; i++) thing[i] = 2000000000000000000;
    for (long long i = 0; i < n; i++) cin >> arr[i].second;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        arr[i].first = arr[i].second - x;
        thing[arr[i].second] = min(thing[arr[i].second], arr[i].first);
    }
    sort(arr, arr + n); // why not
    for (long long i = 1; i < 1000004; i++) {
        thing[i] = min(thing[i], thing[i - 1]);
    }
    for (long long i = 0; i < 1000004; i++) {
        if (i - thing[i] < 0) continue;
        dp[i] = 1 + dp[i - thing[i]];
    }
    long long res = 0;
    for (long long i = 0; i < m; i++) {
        long long x;
        cin >> x;
        if (x > 1000000) {
            long long amnt = (x - arr[0].second) / arr[0].first + ((x - arr[0].second) % arr[0].first != 0);
            if (x - amnt * arr[0].first < 0) amnt--;
            x -= amnt * arr[0].first;
            res += amnt;
        }
        res += dp[x];
    }
    cout << res * 2 << endl;


    return 0;
}