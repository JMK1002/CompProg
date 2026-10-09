//
// Created by JMKov on 9/11/2024.
//
#include <iostream>
#include <map>
#include <set>
using namespace std;

const long long mod = 1004024039;
const long long mod2 = 1000000007;

long long n, m;
long long pw[200005];
set<pair<long long, bool>> events[200005];
map<pair<long long, long long>, long long> mp;

void solve() {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        events[a].insert({i, true});
        events[b].insert({i, false});
    }
    pair<long long, long long> v = {0, 0};
    for (long long i = 1; i <= n; i++) {
        for (pair<long long, long long> j: events[i]) {
            if (j.second) {
                v.first += pw[j.first];
                v.second += pw[j.first];
            }
            else {
                v.first -= pw[j.first];
                v.second -= pw[j.first];
            }
            v.first %= mod;
            v.first += mod;
            v.first %= mod;
            v.second %= mod2;
            v.second += mod2;
            v.second %= mod2;
        }
        mp[v]++;
    }
    pair<long long, pair<long long, long long>> mx = {0, {0, 0}};
    for (pair<pair<long long, long long>, long long> i : mp) {
        mx = max(mx, {i.second, i.first});
    }
    cout << n - mx.first << endl;

    for (long long i = 0; i <= n + 1; i++) {
        events[i].clear();
    }
    mp.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    pw[0] = 1;
    for (long long i = 1; i < 200005; i++) pw[i] = (pw[i - 1] * 2) % mod;
    while (t--) {
        solve();
    }
    return 0;
}