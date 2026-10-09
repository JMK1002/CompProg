#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long n;
set<long long> adj[200005];
bool col[200005]; // true is black
long long sz[200005];

void dfs(long long v, long long p) {
	long long cnt = 0;
	sz[v] = 1;
	for (long long e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
		cnt += col[e];
		sz[v] += col[e] * sz[e];
	}
	col[v] = (cnt + 1) % 2;
}

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

long long inv(long long a) {
	return binpow(a, mod - 2);
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
	vector<int> st;
	for (int i = 1; i < n; i++) if (!col[i]) {
		st.push_back(i);
	}
	long long fact = 1;
	for (long long i = 1; i <= (long long) st.size() - 1; i++) { // ! factorial
		fact *= i;
		fact %= mod;
	}
	long long prod = 1;
	long long s = 0;
	for (int i : st) {
		prod *= sz[i];
		prod %= mod;
		s += inv(sz[i]);
		s %= mod;
	}
	long long init = sz[0];

	long long res;
	if (st.size() != 0) res = fact * prod % mod * prod % mod * s % mod * init % mod;
	else res = 1;
	cout << res << endl;
	for (long long i = 0; i <= n; i++) {
		col[i] = 0;
		sz[i] = 0;
		adj[i].clear();
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);br
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}