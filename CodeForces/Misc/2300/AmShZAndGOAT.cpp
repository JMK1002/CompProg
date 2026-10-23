#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int arr[200005];

void solve() {
	cin >> n;
	map<int, int> asdf;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		asdf[arr[i]]++;
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		if (!i || arr[i - 1] != arr[i]) a.push_back(arr[i]);
	}
	int res = asdf[a[a.size() - 1]];
	for (int i = 0; i < a.size() - 1; i++) {
		int cnt = asdf[a[i]];
		int ind = i + 1;
		while (ind != a.size()) {
			cnt++;
			ind = lower_bound(a.begin(), a.end(), a[i] + 2 * (a[ind] - a[i])) - a.begin();

		}
		res = max(res, cnt);
	}
	cout << n - res << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
