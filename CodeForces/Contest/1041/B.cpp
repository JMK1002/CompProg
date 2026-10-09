#include <bits/stdc++.h>
using namespace std;

int n, x;
string s;

void solve() {
	cin >> n >> x >> s;
	x--;
	int lx = x;
	int rx = x;
	while (rx < n && s[rx] != '#') rx++;
	while (lx >= 0 && s[lx] != '#') lx--;
	lx++; rx--;

	cout << max(min(lx + 1, n - x), min(n - rx, x + 1)) << endl;
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