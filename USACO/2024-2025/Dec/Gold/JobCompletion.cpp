#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

long long n;
set<pair<long long, long long>> dp[200005];
pair<long long, long long> arr[200005];

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    long long ans = 0;
    sort(arr, arr + n);
    dp[0].insert({arr[0].second, 1});
    for (long long i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        dp[i].insert({arr[i].second, 1});
        for (pair<long long, long long> j : dp[i - 1]) {
            if (j.first > arr[i].first) continue;
            if (1e18 + 2 - j.first < arr[i].second) ans = max(ans, j.second + 1);
            else dp[i].insert({j.first + arr[i].second, j.second + 1});
        }
        vector<pair<long long, long long>> del;
        long long mx = 0;
        for (pair<long long, long long> p : dp[i]) {
            if (p.second <= mx) del.push_back(p);
            else {
                mx = p.second;
                ans = max(ans, mx);
            }
        }
        for (pair<long long, long long> p : del) dp[i].erase(p);
    }
    cout << ans << endl;

    for (long long i = 0; i <= n; i++) {
        dp[i].clear();
        arr[i] = {0, 0};
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    // ! smells of dp
    // ! optimized knapsack gets 50% solve
    // ? 110 min left: for some reason am getting a ton of TLE and RTE...
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}