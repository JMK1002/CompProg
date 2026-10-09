#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int d1[105*105];
int ans[105][105];

int ask(int i, int j) {
	cout << "? " << i << " " << j << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}

void solve() {
	cin >> n;
	int mx = 0;
	int c1 = 1;
	for (int i = 1; i <= n * n; i++) {
		int amnt = ask(1, i);
		if (amnt > mx) {
			c1 = i;
			mx = amnt;
		}
	}
	vector<int> mid;
	for (int i = 1; i <= n * n; i++) {
		int amnt = ask(c1, i);
		d1[i] = amnt;
		if (amnt == n - 1) mid.push_back(i);
	}
	int c2 = mid[0];
	mx = 0;
	for (int i = 0; i < n; i++) {
		int amnt = ask(mid[0], mid[i]);
		if (amnt > mx) {
			c2 = mid[i];
			mx = amnt;
		}
	}
	for (int i = 1; i <= n * n; i++) {
		int d2 = ask(c2, i);
		int y = (d1[i] + d2 - (n - 1)) / 2;
		ans[d1[i] - y][y] = i;
	}
	cout << "!" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
			ans[i][j] = 0;
		}
		cout << endl;
	}
	cout.flush();
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
