#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long n, m;
long long fact[200005];
long long cnt[200005];
set<long long> adj[200005];
set<long long> rem[200005];
long long val = 1;

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		long long u, v;
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
		rem[u].insert(v);
		rem[v].insert(u);
	}
	long long ln = n;
	for (long long i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			long long e = *adj[i].begin();
			rem[e].erase(i);
			rem[i].erase(e);
			ln--;
		}
	}
	vector<long long> newLeafs;
	for (long long i = 1; i <= n; i++) {
		if (rem[i].size() == 1) newLeafs.push_back(i);
	}
	if (newLeafs.size() > 2 || m != n - 1) {
		cout << 0 << endl;
		return;
	}
	else if (newLeafs.size() == 0) {
		cout << (2 * fact[n - 1] % mod) << endl;
		return;
	}

	for (long long i = 1; i <= n; i++) {
		for (long long e : adj[i]) {
			cnt[i] += adj[e].size() == 1;
		}
		val *= fact[cnt[i]];
		val %= mod;
	}

	cout << (4 * val % mod) << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	fact[0] = 1;
	for (long long i = 1; i <= 200000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	long long t;
	cin >> t;
	while (t--) {
		solve();

		for (long long i = 0; i <= n; i++) {
			adj[i].clear();
			rem[i].clear();
			cnt[i] = 0;
		}
		val = 1;
	}
	return 0;
}

// 7 6
// 1 2
// 1 3
// 1 4
// 2 5
// 3 6
// 4 7