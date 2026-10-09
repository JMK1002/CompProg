#include <bits/stdc++.h>
using namespace std;

void solve() {
	int x, y;
	cin >> x >> y;
	if (y == 1 || x == y) {
		cout << -1 << endl;
		return;
	}
	if (x < y) {
		cout << 2 << endl;
		return;
	}
	else {
		x--;
		if (y < x) cout << 3 << endl;
		else cout << -1 << endl;
		return;
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