#include <bits/stdc++.h>
using namespace std;

int n, m;
multiset<int> a;
pair<int, int> b[200005];
int c[200005];

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.insert(x);
	}
	for (int i = 0; i < m; i++) cin >> b[i].first;
	for (int i = 0; i < m; i++) cin >> b[i].second;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (b[i].second == 0) {
			c[cnt] = b[i].first;
			b[i] = {1e9+2, 0};
			cnt++;
		}
	}
	sort(b, b + m);
	sort(c, c + cnt);
	int ptr = 0;
	int ptr2 = 0;
	while (!a.empty() && (ptr < m - cnt || ptr2 < cnt)) {
		int w = *a.begin();
		if (ptr < m - cnt && w >= b[ptr].first) {
			if (b[ptr].second > w) {
				a.erase(a.begin());
				a.insert(b[ptr].second);
			}
			ptr++;
		}
		else if (ptr2 < cnt && w >= c[ptr2]) {
			ptr2++;
			a.erase(a.begin());
		}
		else {
			a.erase(a.begin());
		}
	}
	cout << ptr + ptr2 << endl;
	a.clear();
	for (int i = 0; i <= m; i++) b[i] = {0, 0};
	for (int i = 0; i <= m; i++) c[i] = 0;
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