#include <bits/stdc++.h>
using namespace std;

#define int long long

struct cell {
	int x, y;
	cell() : x(0), y(0) {}
	cell(int x, int y) : x(x), y(y) {}
	bool operator == (const cell & a) const {
		return make_pair(x, y) == make_pair(a.x, a.y);
	}
	bool operator < (const cell & a) const {
		return make_pair(x, y) < make_pair(a.x, a.y);
	}
};

const pair<int, int> dirs[4] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

map<char, pair<int ,int>> dirsMap = {
	{'L', {0, 1}},
	{'R', {0, -1}},
	{'U', {1, 0}},
	{'D', {-1, 0}},
};

int n, m, p, q;
vector<vector<vector<pair<cell, int>>>> adj;
vector<string> arr;
vector<vector<int>> dist;
vector<vector<bool>> explored;

void solve() {
	cin >> n >> m >> p >> q;
	string temp;
	for (int i = 0; i < m + 2; i++) temp += '#';
	arr.push_back(temp);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr.push_back("#" + s + "#");
	}
	adj = vector<vector<vector<pair<cell, int>>>>(n + 2, vector<vector<pair<cell, int>>>(m + 2));
	arr.push_back(temp);
	vector<cell> start;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '.') start.push_back(cell(i, j));
			for (auto dir : dirs) {
				int nx = i + dir.first;
				int ny = j + dir.second;
				if (arr[nx][ny] == '#' || arr[nx][ny] == '.') continue;
			 	pair<int, int> mpDir = dirsMap[arr[nx][ny]];
				bool isStraight = mpDir.first * dir.first + mpDir.second * dir.second;
				nx += mpDir.first;
				ny += mpDir.second;
				adj[i][j].push_back({cell(nx, ny), (isStraight ? q : p)});
			}
		}
	}
	dist = vector<vector<int>>(n + 2, vector<int>(m + 2, 1e16));
	explored = vector<vector<bool>>(n + 2, vector<bool>(m + 2));
	set<pair<int, cell>> qu;
	for (cell c : start) {
		qu.insert({0, c});
		dist[c.x][c.y] = 0;
	}
	while (!qu.empty()) {
		int d = qu.begin()->first;
		cell c = qu.begin()->second;
		explored[c.x][c.y] = true;
		qu.erase(qu.begin());
		for (auto edge : adj[c.x][c.y]) {
			int weight = edge.second;
			cell v = edge.first;
			if (explored[v.x][v.y] || dist[v.x][v.y] <= weight + dist[c.x][c.y]) continue;
			qu.erase({dist[v.x][v.y], v});
			dist[v.x][v.y] = weight + dist[c.x][c.y];
			qu.insert({dist[v.x][v.y], v});
		}
	}
	int ans = 1e16;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = min(ans, dist[i][j] + dist[i + 1][j]);
			ans = min(ans, dist[i][j] + dist[i][j + 1]);
		}
	}
	if (ans >= 1e16) cout << -1 << endl;
	else cout << ans << endl;

	adj.clear();
	arr.clear();
	dist.clear();
	explored.clear();
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
