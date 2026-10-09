#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
	cin >> n;
	int mn = 2000000000;
	int mx = -2000000000;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mn = min(mn, x);
		mx = max(mx, x);
	}
	int x;
	cin >> x;
	if (x <= mx && x >= mn) cout << "YES" << endl;
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