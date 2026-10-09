#include <iostream>
using namespace std;

int n, q;
int arr[200005];
int inv[200005];

void solve() { 
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		inv[arr[i]] = i;
	}
	while (q--) {
		int l, r, k;
		cin >> l >> r >> k;
		int i = inv[k];
		if (i > r || i < l) {
			cout << -1 << " ";
			continue;
		}
		int a = 0;
		int b = 0; // swap from low to high
		int c = 0;
		int d = 0;
		while (l <= r) {
			int m = (l + r) / 2;
			if (arr[m] == k) break;
			if (i < m) {
				r = m - 1;
				if (arr[m] < k) b++;
				else d++;
			}
			else {
				l = m + 1;
				if (arr[m] > k) a++;
				else c++;
			}
		}
		int cnt = max(a, b) * 2;
		int x = min(a, b);
		if (max(a, b) > n - k - d || max(a, b) > k - 1 - c) {
			cout << -1 << " ";
			continue;
		}
		cout << cnt << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		inv[i] = 0;
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