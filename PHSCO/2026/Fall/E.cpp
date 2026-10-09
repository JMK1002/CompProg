#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long a, b;
	cin >> a >> b;
	long long run = 1;
	while (run <= a + b) run <<= 1;
	run--;
	if (b >= 2) cout << run << endl;
	else if (b == 1) cout << a + b << endl;
	else cout << 0 << endl;
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