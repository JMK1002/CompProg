#include <bits/stdc++.h>
using namespace std;

int cnt[200005];

void solve() {
	int n;
	cin >> n;
	bool ans = false;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		cnt[x]++;
		if (cnt[x] > 1) {
			ans = true;
		}
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;

	for (int i = 0; i <= 101; i++) cnt[i] = 0;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}