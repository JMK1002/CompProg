#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];

void solve() {
	cin >> n;
	long long s = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == 1) s += arr[i];
		else s += abs(arr[i]);
	}
	long long ans = -1000000000000000000;
	for (long long i = n; i >= 1; i--) {
		if (i == 1) s -= arr[i];
		else s -= abs(arr[i]);
		ans = max(ans, s);
		s -= arr[i];
	}
	cout << ans << endl;
	for (long long i = 0; i <= n; i++) arr[i] = 0;
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