//
// Created by JMKov on 7/20/2024.
//
#include <iostream>
using namespace std;

const long long INF = 2000000000000000;
const long long mod = 1000000007;

string a, b;
pair<long long, long long> dp[505][2];

pair<long long, long long> get(long long i, long long j) {
    return (i < 0) ? make_pair(0ll, 1ll) : dp[i][j];
}

void solve() {
    cin >> a >> b;
    long long n = a.size();
    long long nb = b.size();
    for (long long i = 0; i < n; i++) {
        bool copy = true;
        for (long long j = i - nb + 1; j <= i; j++) {
            if (j < 0 || a[j] != b[j - (i - nb + 1)]) {
                copy = false;
                break;
            }
        }
        if (copy) {
            pair<long long, long long> p1 = get(i - nb, 0);
            pair<long long, long long> p2 = get(i - nb, 1);

            dp[i][1] = (p1.first == p2.first && p1.first != 0) ? make_pair(p1.first, p1.second + p2.second) : min(p1, p2);
            dp[i][1].first++;
            dp[i][0] = make_pair(INF, INF);
            for (long long j = i - 1; j > i - nb; j--) {
                pair<long long, long long> p = get(j, 1);
                dp[i][0] = (dp[i][0].first == p.first && p.first != 0) ? make_pair(p.first, dp[i][0].second + p.second) : min(dp[i][0], p);
                dp[i][0].second %= mod;
            }
        }
        else {
            pair<long long, long long> p1 = get(i - 1, 0);
            pair<long long, long long> p2 = get(i - 1, 1);

            dp[i][0] = (p1.first == p2.first && p1.first != 0) ? make_pair(p1.first, p1.second + p2.second) : min(p1, p2);
            dp[i][1] = make_pair(INF, INF);
        }
        dp[i][0].second %= mod;
        dp[i][1].second %= mod;
    }
    pair<long long, long long> p1 = get(n - 1, 0);
    pair<long long, long long> p2 = get(n - 1, 1);
    pair<long long, long long> ans = (p1.first == p2.first && p1.first != 0) ? make_pair(p1.first, p1.second + p2.second) : min(p1, p2);
    ans.second %= mod;
    cout << ans.first << " " << ans.second << endl;
//    for (long long i = 0; i < n; i++) cout << dp[i][0].first << " " << dp[i][0].second << " " << dp[i][1].first << " " << dp[i][1].second << endl;
    for (int i = 0; i <= n; i++) {
        dp[i][0] = {0, 0};
        dp[i][1] = {0, 0};
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