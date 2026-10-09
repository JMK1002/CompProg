#include <bits/stdc++.h>
using namespace std;

const int b = 30;

int n;
int arr[200005];
int pre[b][200005];

bool w(int l, int r, int k) {
	int v = 0;
	for (int run = 1, i = 0; i < b; i++, run <<= 1) {
		if (pre[i][r] - pre[i][l - 1] == r - l + 1) v += run;
	}
	return (v >= k);
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int j = 0, run = 1; j < b; j++, run <<= 1) {
		for (int i = 1; i <= n; i++) {
			pre[j][i] = pre[j][i - 1] + (bool) (arr[i] & run);
		}
	}
	int q;
	cin >> q;
	for (int _ = 0; _ < q; _++) {
		int l, k;
		cin >> l >> k;

		if (arr[l] < k) {
			cout << -1 << " ";
			continue;
		}
		if (w(l, n, k)) {
			cout << n << " ";
			continue;
		}
		int low = l;
		int high = n;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (w(l, mid, k)) low = mid;
			else high = mid;
		}
		cout << low << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		for (int j = 0; j < b; j++) {
			pre[j][i] = 0;
		}
	}
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