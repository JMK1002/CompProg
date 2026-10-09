#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	if ((n >= m && n <= 2 * m - 2) || n % 2 == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}

int main() {
	// ulimit -s unlimited
	// 7z e <MyFile>.zip
	freopen("deciding_points_input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	int cnt = 1;
	while (t--) {
		cout << "Case #" << cnt << ": ";
		solve();
		cnt++;
	}
	return 0;
}