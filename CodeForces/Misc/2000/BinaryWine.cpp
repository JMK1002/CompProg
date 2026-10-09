#include <bits/stdc++.h>
using namespace std;

int n, q;
int arr[500005];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	reverse(arr, arr + n);
	while (q--) {
		int c;
		cin >> c;
		multiset<int> ms;
		for (int i = 0; i < min(31, n); i++) ms.insert(arr[i]);
		int ans = 0;
		for (int i = 30, run = 1 << 30; i >= 0; i--, run >>= 1) {
			if (!(c & run)) continue;
			int x = *--ms.end();
			if ((run & x) || x >= run) {
				ms.erase(ms.find(x));
				ms.insert(x - run);
				c -= run;
			}
			else {
				ans += run - x;
				ms.erase(ms.find(x));
				ms.insert(0);
				c -= run;
			}
		}
		cout << ans << endl;

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