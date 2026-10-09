#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[500005];
int inds[500005];
int ans[500005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i].first;
	for (int i = 0; i < n; i++) cin >> arr[i].second;
	iota(inds, inds + n, 0);
	sort(inds, inds + n, [&] (int a, int b) {
		return arr[a] < arr[b];
	});
	sort(arr, arr + n);
	bool works = true;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].second < arr[i].first) {
			works = false;
			break;
		}
		if (arr[i].first == arr[i].second) {
			ans[i] = -1;
			continue;
		}
		int ind = lower_bound(arr, arr + n, make_pair(arr[i].second, -1)) - arr;
		if (ind == n || arr[ind].first != arr[i].second) {
			works = false;
			break;
		}
		ans[i] = ind;
		cnt++;
	}
	if (works) {
		cout << cnt << endl;
		for (int i = 0; i < n; i++) {
			if (ans[i] == -1) continue;
			cout << inds[i] + 1 << " " << inds[ans[i]] + 1 << endl;
		}
	}
	else cout << -1 << endl;
}

int main() {
	freopen("warm_up_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
		cout << "Case #" << cnt << ": ";
		solve();
		cnt++;
	}
	return 0;
}