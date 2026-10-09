#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	int last = -1e9;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (last < i - (k - 1)) {
				ans++;
				last = i;
			}
			else {
				last = i;
			}
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