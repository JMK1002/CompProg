#include <iostream>
#include <set>
using namespace std;

const long long m = 1000000007;

long long n, k;
long long fact[200005];
set<long long> adj[200005];
long long cnt = 0;

long long inv(long long a) {
  return a <= 1 ? a : m - (long long)(m/a) * inv(m % a) % m;
}


long long ch(long long a, long long b) {
    if (a < b) return 0;
    return fact[a] * inv(fact[b]) % m * inv(fact[a - b]) % m;
}

long long dfs(long long v, long long p) {
    long long s = 1;
    for (long long e : adj[v]) {
        if (e == p) continue;
        s += dfs(e, v);
    }
    // cout << v << " " << ch(s - 1, k / 2) * ch(n - s, k / 2) % m + ch(s - 1, k / 2 - 1) + ch(n - s, k / 2) % m + ch(s - 1, k / 2) * ch(n - s, k / 2 - 1) % m << endl;
    cnt += ch(s, k / 2) * ch(n - s, k / 2) % m;
    cnt %= m;
    return s;
}
int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> k;
    for (long long i = 0; i < n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    if (k % 2 == 1) {
        cout << 1 << endl;
        return 0;
    }

    long long x = k / 2;
    fact[0] = 1;
    for (long long i = 1; i < 200005; i++) {
        fact[i] = fact[i - 1] * i % m; 
    }
    long long root = 0;
    for (long long i = 0; i < n; i++) if (adj[i].size() == 1) root = i;
    dfs(root, root);
    // if (k == 2) cnt += n - 1;
    cout << (1 + cnt * inv(ch(n, k))) % m << endl;
    return 0;
}