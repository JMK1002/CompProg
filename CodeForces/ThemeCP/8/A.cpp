#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int cnt[10];

void solve() {
	cin >> n >>s;
	// for (int i = 0; i < n; i++) s += '0';
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int u = 0;
		int mx = 0;
		for (int j = 0; j <= 100, i + j < n; j++) {
			int v = s[i + j] - '0';
			cnt[v]++;
			if (cnt[v] == 1) u++;
			mx = max(mx, cnt[v]);
			if (mx <= u) ans++;
			if (mx > 10) break;
		}
		for (int j = 0; j < 10; j++) cnt[j] = 0;
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