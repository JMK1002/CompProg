#include <bits/stdc++.h>
using namespace std;

int n;
string arr[102];
vector<int> ans[102];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) ans[i].push_back(i);
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (arr[i][j] == '1') {
		ans[j].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i].size() << " ";
		for (int j : ans[i]) cout << j + 1 << " ";
		cout << endl;
	}
	for (int i = 0; i <= n; i++) {
		arr[i].clear();
		ans[i].clear();
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