#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[100005];
int forw[100005];
int backw[100005];

void solve() {
	cin >> n;
	arr[0] = 1e9;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		forw[i] = (arr[i] > arr[i - 1]) ? forw[i - 1] + 1 : 1;
	}
	arr[n + 1] = 1e9;
	for (int i = n; i >= 1; i--) {
		backw[i] = (arr[i] < arr[i + 1]) ? backw[i + 1] + 1 : 1;
	}
	int ans = 1;
	if (n == 1) {
		cout << ans << endl;
		return;
	}
	for (int i = 2; i <= n - 1; i++) {
		if (arr[i + 1] > arr[i - 1] + 1) {
			ans = max(ans, forw[i - 1] + backw[i + 1] + 1);
		}
		else {
			ans = max(ans, max(forw[i - 1] + 1, backw[i + 1] + 1));
		}
	}
	ans = max(ans, max(1 + forw[n - 1], 1 + backw[2]));
	cout << ans << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
