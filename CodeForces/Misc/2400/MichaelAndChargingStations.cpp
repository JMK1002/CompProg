#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[300005];
int pre[300005];

int sum(int l, int r) {
	if (r < l) return 0;
	return pre[r] - pre[l - 1];
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		pre[i] = pre[i - 1] + arr[i];
	}
	int tot = sum(1, n);
	int ans = tot;
	for (int i = n; i >= 1; i--) {
		ans = min(ans, tot - min(sum(1, i) / 10, sum(i + 1, n)));
	}
	int lst = n + 1;
	for (int i = n; i >= 1; i--) {
		if (arr[i] == 1000) {
			lst = i;
			continue;
		}
		int a = sum(1, i - 1);
		int b = sum(i, lst - 1);
		int c = sum(lst + 1, n);
		ans = min(ans, tot - (min(a / 10, b) + min(max(0ll, a / 10 - b) + 100, c)));
	}
	lst = n + 1;
	for (int i = n; i >= 1; i--) {
		if (arr[i] == 2000) continue;
		int a = sum(1, i - 1);
		while (lst > i) {
			int b = sum(i + 1, lst - 1);
			int c = sum(lst, n);
			ans = min(ans, tot - (min(a / 10, 1000ll) + min(max(0ll, a / 10 - 1000) + b / 10, c)));
			lst--;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		pre[i] = 0;
	}
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
