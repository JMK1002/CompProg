#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long n, m, k;
long long h[100005];
long long x[100005];
vector<pair<long long, long long>> evs;

bool works(long long times) {
	evs.clear();
	for (long long i = 0; i < n; i++) {
		long long d = m - (h[i] / times + (h[i] % times != 0));
		if (d < 0) continue;
		evs.push_back({x[i] - d, 1});
		evs.push_back({x[i] + d + 1, -1});
	}
	sort(evs.begin(), evs.end());
	long long run = 0;
	for (auto p : evs) {
		run += p.second;
		if (run == k) return true;
	}
	return false;
}

void solve() {
	cin >> n >> m >> k;
	long long mx = 0;
	for (long long i = 0; i < n; i++) {
		cin >> h[i];
		mx = max(mx, h[i]);
	}
	for (long long i = 0; i < n; i++) cin >> x[i];
	long long low = 0;
	long long high = mx;
	if (!works(high)) {
		cout << -1 << endl;
		return;
	}
	while (high - low > 1) {
		long long mid = (low + high) / 2;
		if (works(mid)) high = mid;
		else low = mid;
	}
	cout << high << endl;
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