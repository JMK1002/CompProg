#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[5005];
long long dp[5005];
long long temp[5005];

const long long mod = 998244353;

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	vector<long long> v;
	long long cnt = 0;
	for (long long i = 0; i < n; i++) {
		if (i > 0 && arr[i] != arr[i - 1]) {
			v.push_back(cnt);
			cnt = 0;
		}
		cnt++;
	}
	v.push_back(cnt);
	dp[0] = 1;
	int a = 0;
	sort(v.begin(), v.end());
	for (long long x : v) {
		a++;
		for (long long i = 0; i <= n; i++) {
			if (a != v.size() || i >= x) temp[i] += dp[i];
			
			if (i + x <= n) {
				temp[i + x] += dp[i] * x % mod;
				temp[i + x] %= mod;
			}
			temp[i] %= mod;

		}
		for (long long i = 0; i <= n; i++) {
			dp[i] = temp[i];
			temp[i] = 0;
		}
	}
	long long ans = 0;
	for (long long i = 0; i <= n; i++) {
		ans += dp[i];
		ans %= mod;
	}
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) {
		dp[i] = 0;
		temp[i] = 0;
		arr[i] = 0;
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