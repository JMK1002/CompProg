#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
	}
	else if (n == 2) {
		cout << 9 << endl;
	}
	else {
		int x = n * n;
		int a = x + (x - 1) + (x - n);
		int b = x + (x - 1) + (x - 2) + (x - 1 - n);
		int c = x + (x - n) + (x - 2 * n) + (x - 1 - n);
		int d = (x - 1) + (x - n) + (x - n - 1) + (x - n - 2) + (x - 2 * n - 1);
		cout << max(max(a, b), max(c, d)) << endl;
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