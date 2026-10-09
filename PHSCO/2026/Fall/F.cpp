#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, x, y;
	cin >> n >> x >> y;
	if (n == 2 || x == 2 && y == 1 || x == 1 && y == 2) {
		cout << 1 << endl;
		return;
	}

	if (n % 2 == 0) cout << n * n - 2 << endl;
	else if ((x + y) % 2 == 0) cout << n * n - 1 << endl;
	else cout << n * n - 3 << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}