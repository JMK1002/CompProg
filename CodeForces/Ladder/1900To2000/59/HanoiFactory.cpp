//
// Created by JMKov on 8/12/2023.
//
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <numeric>
#include <set>

using namespace std;

long long n;
long long dp[100003];
pair<long long, pair<long long, long long>> arr[100010];

bool compare(pair<long long, pair<long long, long long>> a, pair<long long, pair<long long, long long>> b) {
    if (a.second.first == b.second.first) {
        return a.first > b.first;
    }
    return a.second.first > b.second.first;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second.first >> arr[i].second.second; // a, b, h;
    }
    sort(arr, arr + n, compare);
//    for (long long i = 0; i < n; i++) cout << arr[i].second.first << " ";
//    cout << endl;
//    for (long long i = 0; i < n; i++) cout << arr[i].first << " ";
//    cout << endl;
//    for (long long i = 0; i < n; i++) cout << arr[i].second.second << " ";
//    cout << endl;
    long long ans = 0;
    set<pair<long long, long long>> inr;
    inr.emplace(0, -1);
    for (long long i = 0; i < n; i++) {
        if (i != 0 && arr[i].second.first <= arr[i - 1].first) {
            ans = max(dp[i], ans);
            long long v = (*(inr.lower_bound({arr[i].second.first, i}))).second;
            dp[i + 1] = dp[v + 1] + arr[i].second.second;
        }
        else {
            dp[i + 1] = dp[i] + arr[i].second.second;
        }
        inr.emplace(arr[i].second.first, i);
    }
    ans = max(dp[n], ans);
    cout << ans << endl;
//    for (long long i = 0; i <= n; i++) cout << dp[i] << " ";
//    cout << endl;
    return 0;
}