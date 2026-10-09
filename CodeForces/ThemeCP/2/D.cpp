#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long n;
set<long long> adj[200005];
long long d[200005];

long long binpow(long long a, long long b) {
	long long run = a;
	long long res = 1;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		res %= mod;
		run %= mod;
		b >>= 1;
	}
	return res;
}

void dfs(long long v, long long p) {
	d[v] = 1;
	for (long long e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
		d[v] = max(d[v], d[e] + 1);
	}
}

void solve() {
	cin >> n;
	for (long long i = 0; i < n - 1; i++) {
		long long u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(0, 0);
	long long s = 0;
	for (long long i = 0; i < n; i++) {
		s += d[i];
		s %= mod;
	}
	s *= binpow(2, n - 1);
	s %= mod;
	cout << s << endl;
	for (long long i = 0; i < n; i++) {
		adj[i].clear();
		d[i] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}