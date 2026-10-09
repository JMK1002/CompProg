#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.size();
	int ans = 0;
	if (s[0] == 'u') {
		s[0] = 's';
		ans++;
	}
	if (s[n - 1] == 'u') {
		s[n - 1] = 's';
		ans++;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'u') {
			cnt++;
		}
		else {
			ans += cnt / 2;
			cnt = 0;
		}
	}
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