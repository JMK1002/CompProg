#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;

void solve() {
	cin >> n >> q >> s;
	bool hasB = false;
	for (int i = 0; i < n; i++) hasB |= s[i] == 'B';
	for (int i = 0; i < q; i++) {
		int x;
		cin >> x;
		if (!hasB) {
			cout << x << endl;
			continue;
		}
		int cnt = 0;
		while (x) {
			if (s[cnt % n] == 'A') x--;
			else x /= 2;
			cnt++;
		}
		cout << cnt << endl;
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