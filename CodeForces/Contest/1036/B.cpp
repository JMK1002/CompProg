#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

int n;
int arr[200005];

void solve() {
	cin >> n;
	// int ans = 1000000000;
	// int mn = 1000000000;
	// int run = 0;
	// int gap = 1000000000;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	if (n == 1) cout << arr[0] << endl;
	else {
		cout << min(arr[0] + arr[1], arr[0] * 2) << endl;
	}
	// for (int i = 0; i < n; i++) {
	// 	mn = min(arr[i], mn);
	// 	if (i != 0) gap = min(gap, max(0, arr[i - 1] - arr[i]));
	// 	run += mn;
	// 	ans = min(ans, run + min(gap, arr[i + 1]));
	// }
	// cout << ans << endl;
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
	return 0;
}