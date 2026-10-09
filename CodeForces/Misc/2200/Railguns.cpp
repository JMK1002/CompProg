#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

const pair<int, int> dirs[2] = {
	{1, 0},
	{0, 1}
};

int n, m, r;
vector<pair<int, pair<int, int>>> shots;
vector<bool> explored[10004];

void solve() {
	cin >> n >> m >> r;

	for (int i = 0; i <= n + 1; i++) explored[i] = vector<bool>(m + 2);
	for (int i = 0; i < r; i++) {
		int t, d, coord;
		cin >> t >> d >> coord;
		shots.push_back({t, {d, coord}});
	}
	sort(shots.begin(), shots.end());

	int t = 0;
	int ptr = 0;
	queue<pair<int, int>> q;
	q.push({0, 0});
	explored[0][0] = true;
	int ans = -1;
	while (!q.empty() && ans == -1) {
		int sz = q.size();
		for (int i = 0; i < sz; i++) {
			pair<int, int> v = q.front();
			q.pop();

			if (v.first == n && v.second == m) {
				ans = t;
				break;
			}

			for (pair<int, int> dir : dirs) {
				int nx = v.first + dir.first;
				int ny = v.second + dir.second;

				if (nx > n || ny > m || explored[nx][ny]) continue;
				explored[nx][ny] = true;
				q.push({nx, ny});
			}
		}
		t++;


		while (ptr < r && shots[ptr].first == t) {
			int c = shots[ptr].second.second;
			if (shots[ptr].second.first == 1) { // horizontal
				for (int i = 0; i <= m; i++) {
					if (c > 0 && explored[c][i] && explored[c - 1][i]) {
						q.push({c - 1, i});
					}
					explored[c][i] = false;
				}

				queue<pair<int, int>> temp;
				while (!q.empty()) {
					pair<int, int> v = q.front();
					q.pop();
					if (v.first == c) continue;
					temp.push(v);
				}

				q = temp;
			}
			else {
				for (int i = 0; i <= n; i++) {
					if (c > 0 && explored[i][c] && explored[i][c - 1]) {
						q.push({i, c - 1});
					}
					explored[i][c] = false;
				}

				queue<pair<int, int>> temp;
				while (!q.empty()) {
					pair<int, int> v = q.front();
					q.pop();
					if (v.second == c) continue;
					temp.push(v);
				}

				q = temp;
			}
			ptr++;
		}
	}

	cout << ans << endl;

	shots.clear();
	for (int i = 0; i <= n; i++) explored[i].clear();
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