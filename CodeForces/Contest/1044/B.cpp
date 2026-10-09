#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[200005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	reverse(arr, arr + n);
	long long ans = 0;
	for (int i = 0; i < n; i+=2) {
		ans += arr[i];
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) arr[i] = 0;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}