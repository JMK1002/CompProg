#include <bits/stdc++.h>
using namespace std;

long long n;
// long long arr[1000005];
// long long dp[1000005];
map<long long, long long> cnt;

void solve() {
	cin >> n;
	long long pre = 0;
	long long ans = n * (n + 1) * (n + 2) / 6;
	for (long long i = 0; i < n; i++) {
		cnt[pre]++;
		// cin >> arr[i];
		long long a;
		cin >> a;
		pre ^= a;
		ans -= cnt[pre] * (cnt[pre] + 1) / 2;
		// dp[i] = cnt[pre];
	}
	// for (long long i = 0; i < n; i++) cout << dp[i] << " ";
	// cout << endl;
	cout << ans << endl;
	// for (long long i = 0; i <= n; i++) {
		// arr[i] = 0;
		// dp[i] = 0;
	// }
	cnt.clear();
}

int main() {
	// ulimit -s unlimited
	freopen("narrowing_down_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	long long asdf = 1;
	while (t--) {
		cout << "Case #" << asdf << ": ";
		solve();
		asdf++;
	}
	return 0;
}