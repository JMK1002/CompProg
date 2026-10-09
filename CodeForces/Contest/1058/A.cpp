#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> inds;
	vector<int> ans(2 * n + 4, 0);
	for (int i = 1; i <= 2 * n; i++) {
		inds.push_back(i);
		cout << "? " << inds.size() << " ";
		for (int j : inds) cout << j << " ";
		cout << endl;
		cout.flush();

		int v;
		cin >> v;
		if (v) {
			ans[i] = v;
			inds.pop_back();
		}
	}
	inds.clear();
	for (int i = 1; i <= 2 * n; i++) if (ans[i]) inds.push_back(i);
	for (int i = 2 * n; i >= 1; i--) {
		if (ans[i]) continue;
		inds.push_back(i);
		cout << "? " << inds.size() << " ";
		for (int j : inds) cout << j << " ";
		cout << endl;
		cout.flush();

		int v;
		cin >> v;
		if (v) {
			ans[i] = v;
			inds.pop_back();
		}
	}
	cout << "! ";
	for (int i = 1; i <= 2 * n; i++) cout << ans[i] << " ";
	cout << endl;
	cout.flush();
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