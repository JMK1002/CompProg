#include <bits/stdc++.h>
using namespace std;

long long n, k;
pair<long long, long long> arr[200005];

void solve() {
	cin >> n >> k;
	for (long long i = 0; i < n; i++) cin >> arr[i].first;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i].second;
		if (arr[i].second < arr[i].first) swap(arr[i].first, arr[i].second);
	}
	sort(arr, arr + n);
	long long mn = 1e9 + 8;
	for (long long i = 1; i < n; i++) {
		mn = min(mn, arr[i].first - arr[i - 1].second);
	}
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		ans += abs(arr[i].first - arr[i].second);
	}
	if (mn >= 0) ans += 2 * mn;
	cout << ans << endl;
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