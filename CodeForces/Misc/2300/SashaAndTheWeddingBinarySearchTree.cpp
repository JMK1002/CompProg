//
// Created by JMKov on 8/12/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const long long mod = 998244353;

long long n, c;
pair<long long, long long> children[500005];
long long vals[500005];
long long parent[500005];
vector<long long> ord;

long long inv(long long a) {
    return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
    b = max(b, a - b);
    long long ret = 1;
    for (long long i = a; i > b; i--) {
        ret *= (i % mod);
        ret %= mod;
    }
    b = min(b, a - b);
    for (long long i = 1; i <= b; i++) {
        ret *= inv(i);
        ret %= mod;
    }
    return ret;
}

void dfs(long long v) {
    if (v < 0) return;
    dfs(children[v].first);
    ord.push_back(v);
    dfs(children[v].second);
}

void solve() {
    cin >> n >> c;
    for (long long i = 0; i < n; i++) parent[i] = -1;
    for (long long i = 0; i < n; i++) {
        cin >> children[i].first >> children[i].second >> vals[i];
        children[i].first--; children[i].second--;
        if (children[i].first != -2) parent[children[i].first] = i;
        if (children[i].second != -2) parent[children[i].second] = i;
    }
    long long root = 0;
    for (long long i = 0; i < n; i++) if (parent[i] == -1) root = i;
    dfs(root);
    long long ans = 1;
    long long mn = 1;
    long long cnt = 0;
    for (long long i = 0; i < n; i++) {
        if (vals[ord[i]] != -1) {
            long long k = vals[ord[i]] - mn + 1;
            ans *= choose(cnt + k - 1, k - 1);
            ans %= mod;
            cnt = 0;
            mn = vals[ord[i]];
        }
        else {
            cnt++;
        }
    }
    long long k = c - mn + 1;
    ans *= choose(cnt + k - 1, k - 1);
    ans %= mod;
    cout << ans << endl;
    ord.clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}