#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, y, r;
	cin >> n >> y >> r;
	cout << min(n, y / 2 + r) << endl;
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