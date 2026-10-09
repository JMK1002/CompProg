#include <iostream>
#include <map>
#include <queue>
using namespace std;

int n, m, i, j, a, b;
map<pair<int, int>, int> dist;

pair<int,int> dirs[4];

int test(int x, int y) {
	int dx = abs(i - x);
	int dy = abs(j - y);
	if (dx % a != 0 || dy % b != 0 || (dx / a + dy / b) % 2 != 0) return 2000000000;
	else return max(dx / a, dy / b);
}

void solve() {
	cin >> n >> m >> i >> j >> a >> b;
	bool canMove = ((i + a <= n || i - a >= 1) && (j + b <= m || j - b >= 1));
	int ans;
	ans = min(min(test(1, 1), test(n, 1)), min(test(1, m), test(n, m)));
	if ((!canMove && ans != 0) || ans == 2000000000) cout << "Poor Inna and pony!" << endl;
	else cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}