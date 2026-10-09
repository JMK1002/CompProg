#include <bits/stdc++.h>
using namespace std;

int n, q;
pair<int, int> a[300005];
int nxt[300005];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) nxt[i] = -1;
	for (int i = 0; i < q; i++) {
		cin >> a[i].first >> a[i].second;
		a[i].first--; a[i].second--;
		nxt[a[i].first] = max(nxt[a[i].first], a[i].second);
	}
	int mx = -1;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		if (nxt[i] > mx) v.push_back({i, nxt[i]});
		mx = max(mx, nxt[i]);
	}
	int bollocks;
	cout << "? " << 1 << " " << n / 2 << endl;
	cout.flush();
	cin >> bollocks;

	int ans = 0;
	for (pair<int, int> p : v) {
		if (bollocks && p.first >= n / 2) continue;
		else if (!bollocks && p.second < n / 2) continue;
		cout << "? " << p.first + 1 << " " << p.second + 1 << endl;
		cout.flush();
		int x;
		cin >> x;
		ans = max(ans, x);
	}
	cout << "! " << ans << endl;
	cout.flush();

	for (int i = 0; i <= n; i++) nxt[i] = -1;
	for (int i = 0; i <= q; i++) {
		a[i] = {0, 0};
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