#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> st;
int cnt[100005];

void solve() {
	cin >> n >> m;
	st = vector<vector<int>>(n);
	for (int i = 0; i < n; i++) {
		int sz;
		cin >> sz;
		for (int j = 0; j < sz; j++) {
			int x;
			cin >> x;
			st[i].push_back(x);
			cnt[x]++;
		}
	}
	vector<int> works;
	for (int i = 0; i < n; i++) {
		bool asdf = true;
		for (int j = 0; j < st[i].size(); j++) {
			if (cnt[st[i][j]] == 1) {
				asdf = false;
				break;
			}
		}
		if (asdf) works.push_back(i);
	}

	bool asdf = true;
	for (int i = 1; i <= m; i++) if (!cnt[i]) asdf = false;
	if (!asdf || works.size() <= 1) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= m; i++) cnt[i] = 0;
		st.clear();
	}
}