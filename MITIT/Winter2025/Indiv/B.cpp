#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> arr[200005];


void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int res = 2e9;
	for (int _ = 0; _ < 2; _++) {
		sort(arr, arr + n);
		vector<int> pre(n + 2); // prefix max of y
		pre[0] = arr[0].second;
		for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], arr[i].second);
		int worst = 0;
		for (int i = n - 1; i >= 0; i--) {
			res = min(res, max(worst, arr[i].first - arr[0].first));
			worst = max(worst, pre[i] - arr[i].second);
		}
		for (int i = 0; i < n; i++) swap(arr[i].first, arr[i].second);
	}
	cout << res << endl;
	for (int i = 0; i <= n; i++) arr[i] = {0, 0};
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

// 4  
// 0 0
// 1 1
// 3 1
// 6 2