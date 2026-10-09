//
// Created by JMKov on 7/22/2024.
//
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

const long long mod = 998244353;

long long n;
set<pair<pair<long long, long long>, long long>> adj[200005];
long long p[200005];
vector<long long> primes;
long long w[200005];
long long cnt[200005];
long long asdf[200005];
set<long long> ps;

long long binpow(long long a, long long b) {
    long long run = a;
    long long ans = 1;
    while (b != 0) {
        if (b & 1) {
            ans *= run;
            ans %= mod;
        }
        run *= run;
        run %= mod;
        b >>= 1;
    }
    return ans;
}

void sieve() {
    for (long long i = 2; i < 200005; i++) {
        if (p[i] != 0) continue;
        primes.push_back(i);
        for (long long j = i; j < 200005; j += i) {
            p[j] = i;
        }
    }
}

void process(long long v, long long amnt) {
    vector<long long> fact;
    while (v != 1) {
        asdf[p[v]] += amnt;
        fact.push_back(p[v]);
        v /= p[v];
    }
    for (long long i : fact) {
        cnt[i] = min(cnt[i], asdf[i]);
        ps.insert(i);
    }
    fact.clear();
}

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void dfs(long long v, long long p) {
    for (pair<pair<long long, long long>, long long> e : adj[v]) {
        if (e.first.first == p) continue;
        process(e.second, 1);
        process(e.first.second, -1);
        dfs(e.first.first, v);
        process(e.first.second, 1);
        process(e.second, -1);
    }
}

void dfs2(long long v, long long p) {
    for (pair<pair<long long, long long>, long long> e : adj[v]) {
        if (e.first.first == p) continue;
        w[e.first.first] = w[v] * e.second % mod * inv(e.first.second) % mod;
        dfs2(e.first.first, v);
    }
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n - 1; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; b--;
        adj[a].insert({{b, c}, d});
        adj[b].insert({{a, d}, c});
    }
    dfs(0, -1);
    w[0] = 1;
    for (long long prime : primes) {
        w[0] *= binpow(prime, -1 * cnt[prime]);
        w[0] %= mod;
    }
    dfs2(0, -1);
    long long s = 0;
    for (long long i = 0; i < n; i++) s += w[i];
    s %= mod;
    cout << s << endl;

    for (long long i = 0; i <= n; i++) {
        w[i] = 0;
        adj[i].clear();
    }
    for (long long i : ps) {
        cnt[i] = 0;
        asdf[i] = 0;
    }
    ps.clear();
}

int main() {
    sieve();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}