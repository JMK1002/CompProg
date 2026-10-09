#include <iostream>
#include <set>
using namespace std;

int n, m;
pair<int, int> arr[200005];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	if (n >= 20) {
		cout << n << endl;
		for (int i = 1; i <= n; i++) cout << i << " ";
		cout << endl;
		return;
	}
	
	int curr = 0;
	set<int> ans;
	for (int i = 1; i < (1 << n); i++) {
		if (__builtin_popcount(i) > n / 5) continue;
		curr = 0;
		ans.clear();

		int r = 1;
		for (int j = 0; j < n; j++) {
			if (!((curr ^ i) & r)) {
				r <<= 1;
				continue;
			}

			ans.insert(j + 1);
			int r2 = (1 << (j));
			for (int k = j; k < n; k += (j + 1)) {
				curr ^= r2;
				r2 <<= j + 1;
			}
			r <<= 1;
		}
		if (curr != i) continue;

		bool check = true;
		for (int j = 0; j < m; j++) {
			if (ans.find(arr[j].first) != ans.end() && ans.find(arr[j].second) == ans.end()) check = false;
		}

		if (check) {
			// cout << curr << endl;
			cout << ans.size() << endl;
			for (int j : ans) cout << j << " ";
			cout << endl;
			return;
		}
	}
	cout << -1 << endl;
	return;
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
// 100000000110111