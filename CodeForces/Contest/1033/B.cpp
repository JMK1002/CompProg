#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

int n, s;

void solve() {
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x, y, dx, dy;
		cin >> dx >> dy >> x >> y;
		if ((x == y && dx == dy) || (x + y == s && dx + dy == 0)) ans++;
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