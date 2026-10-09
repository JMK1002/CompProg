//
// Created by JMKov on 4/24/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

long long n;
set<long long> adj[5003];
long long dp[5003];

void dfs(long long v, long long p) {
    dp[v]++;
    for (long long e : adj[v]) {
        if (e == p) continue;
        dfs(e, v);
        dp[v] += dp[e];
    }
}

long long calc(long long v) {
    long long s = 0;
    set<long long> sum;
    vector<long long> ad;
    sum.insert(0);
    for (int e : adj[v]) if (dp[v] >= dp[e]) s += dp[e];

    for (long long e : adj[v]) {
        if (dp[v] < dp[e]) continue;
        for (long long k : sum) if (dp[e] + k <= s / 2) ad.push_back(dp[e] + k);
        for (long long i : ad) sum.insert(i);
        ad.clear();
    }
    long long k = *(--sum.end());
//    cout << s << " " << k << endl;
    return k * (s - k);
}

int main() {
    cin >> n;
    for (long long i = 1; i < n; i++) {
        long long x;
        cin >> x;
        x--;
//        x = 0;
        adj[i].insert(x);
        adj[x].insert(i);
    }
    dfs(0, -1);
//    for (long long i = 0; i < n; i++) cout << dp[i] << " ";
//    cout << endl;
    long long ans = 0;
    for (long long i = 0; i < n; i++) {
        if (dp[i] == 1) continue;
        ans += calc(i);
    }
    cout << ans << endl;
}