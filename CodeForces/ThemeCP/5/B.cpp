#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[200005];
long long b[200005];
multiset<pair<long long, bool>> ev;
map<long long, pair<long long, long long>> mp;

void solve() {
	cin >> n >> k;
	for (long long i = 0; i < n; i++) cin >> a[i];
	for (long long i = 0; i < n; i++) cin >> b[i];
	for (long long i = 0; i < n; i++) {
		mp[a[i]].first += 1;
		mp[b[i]].second += 1;
		ev.insert({a[i], false});
		ev.insert({b[i], true});
	}

	long long pos = n;
	long long neg = 0;
	long long ans = 0;	
	for (pair<long long, pair<long long, long long>> p : mp) {
		long long val;
		if (neg > k) val = 0;
		else val = (pos + neg) * p.first;
		ans = max(ans, val);

		pos -= p.second.first;
		neg += p.second.first;
		neg -= p.second.second;
	}
	cout << ans << endl;
	ev.clear();
	mp.clear();
	for (long long i = 0; i <= n; i++) {
		a[i] = 0;
		b[i] = 0;
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