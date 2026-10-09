#include <bits/stdc++.h>
using namespace std;

int n, k;
int arr[200005];
vector<int> inds[200005];

void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		for (int j = 1; j * j <= arr[i]; j++) {
			if (arr[i] % j != 0) continue;
			inds[j].push_back(i);
			if (j * j != arr[i]) {
				inds[arr[i] / j].push_back(i);
			}
		}
	}
	int ans = 1;
	for (int i = 1; i <= n; i++) {
		int ind = lower_bound(arr, arr + n, 4 * i) - arr;
		int e = ind;
		e -= lower_bound(inds[i].begin(), inds[i].end(), ind) - inds[i].begin();
		if (e <= k) ans = i;
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		inds[i].clear();
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