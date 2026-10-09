#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[500005];

void solve() {
	cin >> n;
	arr[0] = 1e9+1;
	arr[1] = 1e9;
	for (long long i = 2; i <= n + 1; i++) cin >> arr[i];
	long long ans = 0;
	long long run = 0;
	for (long long i = 2; i <= n + 1; i++) {
		if (min(arr[i - 2], arr[i - 1]) > arr[i] || arr[i - 2] < arr[i - 1]) run += i - 1;
		else run += 1;
		ans += run;
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
	}
	return 0;
}