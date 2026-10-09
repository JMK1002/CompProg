#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	int run = 0;
	int mn = 0;
	vector<int> ans;
	ans.push_back(0);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '1') run++;
		else run--;
		mn = min(mn, run);
		ans.push_back(run);
	}
	for (int i : ans) cout << i - mn + 1 << " ";
	cout << endl;
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