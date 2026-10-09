#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	long long ans = arr[0] >= arr[1];
	arr[1] = max(arr[1], arr[0]);
	if (arr[0] == arr[1]) arr[0]--;
	long long mx = arr[1];
	for (long long i = 1; i < n; i++) {
		mx = max(arr[i], mx);
		if (i % 2 == 1) arr[i] = mx;
		else {
			ans += max(0ll, arr[i] - arr[i - 1] + 1);
			arr[i] = min(arr[i], arr[i - 1] - 1);
		}
		mx = max(mx, arr[i]);
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) arr[i] = 0;
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