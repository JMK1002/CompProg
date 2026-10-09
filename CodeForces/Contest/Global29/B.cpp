#include <bits/stdc++.h>
using namespace std;


void solve() {
	int n;
	cin >> n;
	for (int i = n - 1; i >= 1; i--) cout << i << " ";
	cout << n << " ";
	for (int i = 1; i <= n; i++) cout << i << " ";
	cout << endl;
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