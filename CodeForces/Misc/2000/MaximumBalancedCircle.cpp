#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];
int cnt[200005];

void solve() {
	cin >> n;
	set<int> vals;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
		vals.insert(arr[i]);
	}
	pair<int, int> rng = {-1, -1};
	int ans = -1;
	int r = -1;
	int run = 0;
	for (int i : vals) {
		if (i < r || i == r && cnt[i] > 1) continue;
		run = 0;
		r = i;
		int l = r;
		run += cnt[r];
		r++;
		while (cnt[r] > 1) {
			run += cnt[r];
			r++;
		}
		if (cnt[r] == 1) {
			run += cnt[r];
			r++;
		}
		r--;

		if (run > ans) {
			ans = run;
			rng = {l, r};
		}
	}

	cout << ans << endl;
	r = rng.second;
	int l = rng.first;
	for (int i = l; i <= r; i++) {
		for (int j = 0; j < cnt[i] - 1; j++) cout << i << " ";
	}
	for (int i = r; i >= l; i--) cout << i << " ";
	cout << endl;

	for (int i : vals) cnt[i] = 0;
	for (int i = 0; i <= n; i++) arr[i] = 0;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}