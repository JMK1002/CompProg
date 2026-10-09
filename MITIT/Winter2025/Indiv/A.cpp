#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
	cin >> s;
	n = s.size();
	int ans = 0;
	int st = 0;
	int m = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (st == -1 && s[i] == 'I') continue;
		else if (st == -1) {
			st = i;
			if (s[i] == 'M') m++;
			if (s[i] == 'T') t++;
			continue;
		}

		if ((i - st) % 2 == 0 && s[i] == 'I') {
			ans += min(m, t / 2);
			st = -1;
			m = 0;
			t = 0;
		}
		else if ((i - st) % 2 == 1 && s[i] != 'I') {
			ans += min(m, t / 2);
			st = i;
			m = 0;
			t = 0;
			if (s[i] == 'M') m++;
			if (s[i] == 'T') t++;
		}
		else if ((i - st) % 2 == 0) {
			if (s[i] == 'M') m++;
			if (s[i] == 'T') t++;
		}
	}
	ans += min(m, t / 2);

	cout << ans << endl;
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