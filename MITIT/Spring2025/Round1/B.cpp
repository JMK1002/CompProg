#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long arr[200005];
pair<long long, long long> diff[200005];

long long check(long long a, long long b) {
	if (abs(diff[a].second - diff[b].second) != 1) return (diff[a].first + diff[b].first);
	return 3000000000;
}

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (long long i = 0; i < n - 1; i++) diff[i] = {arr[i + 1] - arr[i], i};
	sort(diff, diff + (n - 1));
	long long ans = 3000000000;
	for (long long i = 0; i < min(n - 1, 4ll); i++) for (long long j = 0; j < min(n - 1, 4ll); j++) {
		if (i == j) continue;
		ans = min(ans, check(i, j));
	}
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) arr[i] = 0;
	for (long long i = 0; i <= n; i++) diff[i] = {0, 0};
	
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