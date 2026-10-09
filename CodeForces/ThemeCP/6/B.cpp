#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> a, b;
pair<int, int> pos[200005];
int pt[2][200005];

void solve() {
	cin >> n >> m;
	a = vector<vector<int>>(n, vector<int>(m));
	b = vector<vector<int>>(n, vector<int>(m));	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			pos[a[i][j]] = {i, j};
		}
	}
	for (int i = 0; i < n; i++) pt[0][i] = -1;
	for (int i = 0; i < m; i++) pt[1][i] = -1;
	bool works = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> b[i][j];
			int i2 = pos[b[i][j]].first;
			int j2 = pos[b[i][j]].second;

			if (pt[0][i] == -1) pt[0][i] = i2;
			if (pt[1][j] == -1) pt[1][j] = j2;

			if (i2 != pt[0][i] || j2 != pt[1][j]) {
				works = false;
			} 
		}
	}
	if (works) cout << "YES" << endl;
	else cout << "NO" << endl;
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