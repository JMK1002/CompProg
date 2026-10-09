#include <bits/stdc++.h>
using namespace std;

int n;
bool taken[8000];
vector<int> ans;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		int cnt = 0;
		for (int j = l; j < r; j++) {
			cnt += !taken[j];
			taken[j] = true;
		}
		if (cnt != 0) ans.push_back(i + 1);
	}
	cout << ans.size() << endl;
	for (int i : ans) cout << i << " ";
	cout << endl;

	ans.clear();
	for (int i = 0; i <= 2 * n; i++) taken[i] = 0;
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