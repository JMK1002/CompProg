#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int mod = 998244353;

long long n, m;
set<pair<long long, long long>> dp[1005]; 
long long cnt[1005];
set<long long> adj[1005];
bool explored[1005];

void comb(set<pair<long long, long long>> & a, set<pair<long long, long long>> & b) {
	multiset<pair<long long, long long>> tot;
	for (pair<long long, long long> p : a) tot.insert(p);
	for (pair<long long, long long> p : b) tot.insert({p.first + 1, p.second});
	set<pair<long long, long long>> res;
	long long l = -1;
	long long r = -1;
	for (pair<long long, long long> p : tot) {
		if (p.first <= r) {
			r += p.second;
		}
		else {
			res.insert({l, r - l});
			l = p.first;
			r = p.first + p.second;
		}
	}
	res.insert({l, r - l});
	res.erase({-1, 0});

	a.clear();
	for (pair<long long, long long> p : res) {
		if (p.second >= mod) a.insert({p.first, p.second % mod + mod});
		else a.insert(p);
	}
}

void dfs(long long v) {
	explored[v] = true;
	for (long long e : adj[v]) {
		if (explored[e]) continue;
		dfs(e);
	}

	for (long long e : adj[v]) {
		comb(dp[v], dp[e]);
	}
}

void solve() {
	cin >> n >> m;
	for (long long i = 0; i < n; i++) {
		long long x;
		cin >> x;
		if (x == 0) continue;
		dp[i].insert({0, x});
	}
	for (long long i = 0; i < m; i++) {
		long long u, v;
		cin >> u >> v;
		u--; v--;
		cnt[u]++;
		adj[v].insert(u);
	}
	long long end = 0;
	for (long long i = 0; i < n; i++) if (cnt[i] == 0) end = i;

	dfs(end);
	if (dp[end].empty()) {
		cout << 0 << endl;
	}
	else {
		auto p = *(--dp[end].end());
		cout << (p.first + p.second) % mod << endl;
	}

	for (long long i = 0; i <= n; i++) {
		dp[i].clear();
		cnt[i] = 0;
		adj[i].clear();
		explored[i] = false;
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