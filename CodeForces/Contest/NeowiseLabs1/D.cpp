#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> cnt[2];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		y += x;
		cnt[0][x]++;
		cnt[1][y]++;
	}
	int x, y;
	for (pair<int, int> p : cnt[0]) {
		if (p.second % 2 == 1) x = p.first;
	}
	for (pair<int, int> p : cnt[1]) {
		if (p.second % 2 == 1) y = p.first;
	}
	cout << x << " " << (y - x) << endl;
	cnt[0].clear();
	cnt[1].clear();
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