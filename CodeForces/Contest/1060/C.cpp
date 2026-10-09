#include <bits/stdc++.h>
using namespace std;

long long n;
pair<long long, long long> a[200005];
map<long long, long long> cnt;

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> a[i].first;
	}
	for (long long i = 0; i < n; i++) cin >> a[i].second;

	for (long long i = 0; i < n; i++) {
		for (long long j = 1; j * j <= a[i].first; j++) {
			if (a[i].first % j != 0) continue;
			cnt[j]++;
			if (j * j != a[i].first) cnt[a[i].first / j]++;
		}
	}

	for (pair<long long, long long> p : cnt) {
		if (p.first == 1) continue;
		if (p.second > 1) {
			cout << 0 << endl;
			return;
		}
	}
	for (int i = 0; i < n; i++) swap(a[i].first, a[i].second);
	sort(a, a + n);
	for (int i = 0; i < n; i++) swap(a[i].first, a[i].second);
	long long ans = min((long long) 100000000000000000ll, a[0].second + a[1].second);
	for (pair<long long, long long> p : cnt) {
		if (p.first == 1 || p.second == 0) continue;
		if (a[0].first % p.first == 0) continue;
		ans = min(ans, a[0].second * (p.first - a[0].first % p.first));
	}
	for (long long i = 0; i < n; i++) {
		a[i].first++;
		for (long long j = 1; j * j <= a[i].first; j++) {
			if (a[i].first % j != 0) continue;
			
			if (j != 1 && cnt[j] >= 1) {
				ans = min(ans, a[i].second);
			}

			if (a[i].first / j != 1 && j * j != a[i].first && cnt[a[i].first / j] >= 1) {
				ans = min(ans, a[i].second);
			}
		}
	}

	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
		for (long long i = 0; i <= n; i++) {
			a[i].first = 0;
			a[i].second = 0;
		}
		cnt.clear();
	}
	return 0;
}