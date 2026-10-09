#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

long long n, m;
vector<long long> a[200005];
pair<long long, long long> mex[200005];
set<long long> adj[200005];
long long cnt[200005];
long long f[200005];
bool explored[200005];

void dfs(long long v) {
	explored[v] = true;
	for (long long e : adj[v]) {
		if (!explored[e]) dfs(e);
		f[v] = max(f[v], f[e]);
	}
}

void solve() {
	cin >> n >> m;
	long long s = 3;
	for (long long i = 0; i < n; i++) {
		long long l;
		cin >> l;
		s += l;
		for (long long j = 0; j < l; j++) {
			long long x;
			cin >> x;
			a[i].push_back(x);
		}
	}

	long long highestInit = 0;
	for (long long i = 0; i < n; i++) {
		set<long long> cry;
		for (long long j : a[i]) cry.insert(j);
		long long curr = 0;
		while (cry.find(curr) != cry.end()) curr++;
		mex[i].first = curr;
		highestInit = max(highestInit, curr);
		cnt[curr]++;
		curr++;
		while (cry.find(curr) != cry.end()) curr++;
		mex[i].second = curr;
		
		adj[mex[i].first].insert(mex[i].second);
	}

	for (long long i = 0; i <= s; i++) {
		f[i] = max(i, highestInit);
	}
	long long asdf = 0;
	for (long long i = 0; i <= s; i++) {
		if (!explored[i]) dfs(i);
		if (cnt[i] >= 2) asdf = max(asdf, f[i]);
	}
	for (long long i = 0; i <= s; i++) f[i] = max(f[i], asdf);
	long long ans = 0;
	for (long long i = 0; i <= min(s, m); i++) ans += f[i];
	ans += m * (m + 1) / 2 - min(s, m) * (min(s, m) + 1) / 2;
	cout << ans << endl;

	for (long long i = 0; i <= n; i++) {
		a[i].clear();
		mex[i] = {0, 0};
	}
	for (int i = 0; i <= s; i++) {
		f[i] = 0;
		cnt[i] = 0;
		explored[i] = 0;
		adj[i].clear();
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