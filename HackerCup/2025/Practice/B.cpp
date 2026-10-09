#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<string> arr;
vector<vector<bool>> explored;

const pair<int, int> dirs[4] = {
	{-1, 0},
	{0, -1},
	{1, 0},
	{0, 1}
};

int dfs(pair<int, int> p) {
	int res = 1;
	explored[p.first][p.second] = true;
	for (pair<int, int> dir : dirs) {
		pair<int, int> np = {p.first + dir.first, p.second + dir.second};
		if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m || explored[np.first][np.second]) continue;
		res += dfs(np);
	}
	return res;
}

void solve() {
	cin >> n >> m >> s;
	string top;
	for (int i = 0; i < m + 2; i++) top += "#";
	arr.push_back(top);
	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;
		arr.push_back("#" + a + "#");
	}
	arr.push_back(top);
	m += 2;
	n += 2;

	explored = vector<vector<bool>>(n, vector<bool>(m));

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (arr[i][j] == '#') {
		q.push({i, j});
		explored[i][j] = true;
	}
	for (int i = 0; i < s; i++) {
		int sz = q.size();
		for (int j = 0; j < sz; j++) {
			pair<int, int> p = q.front();
			q.pop();
			for (pair<int, int> dir : dirs) {
				pair<int, int> np = {p.first + dir.first, p.second + dir.second};
				if (np.first < 0 || np.first >= n || np.second < 0 || np.second >= m || explored[np.first][np.second]) continue;
				explored[np.first][np.second] = true; 
				q.push(np);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (!explored[i][j]) ans = max(ans, dfs({i, j}));
	cout << ans << endl;

	arr.clear();
	explored.clear();
}

int main() {
	freopen("zone_in_input.txt", "r", stdin);
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