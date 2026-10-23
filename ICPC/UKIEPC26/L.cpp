#include <bits/stdc++.h>
using namespace std;

map<char, pair<int, int>> dirs;
int n;
pair<int, int> pos;
pair<int, int> nxt[102][102];
set<pair<int, int>> in[102][102];
string res;
bool explored[102][102];
bool cycle = false;

string arr[102];

char dir(pair<int, int> a, pair<int, int> b) {
	int dx = b.first - a.first;
	int dy = b.second - a.second;
	char res = '-';
	if (dy == 1) res = 'r';
	if (dy == -1) res = 'l';
	if (dx == 1) res = 'd';
	if (dx == -1) res = 'u';
	return res;
}

void dfs(pair<int, int> curr) {
	if (explored[curr.first][curr.second] || cycle) {
		cycle = true;
		return;
	}
	explored[curr.first][curr.second] = true;
	char desiredDir = arr[curr.first][curr.second];
	pair<int, int> lastBranch = {-1, -1};
	for (pair<int, int> prev : in[curr.first][curr.second]) {
		if (desiredDir == arr[prev.first][prev.second]) lastBranch = prev;
	}

	for (pair<int, int> prev : in[curr.first][curr.second]) {
		if (prev == lastBranch) continue;
		res += dir(curr, prev);
		dfs(prev);
	}
	if (lastBranch.first != -1) {
		res += dir(curr, lastBranch);
		dfs(lastBranch);
	}

	res += dir(curr, nxt[curr.first][curr.second]);
}

void solve() {
	dirs['l'] = {0, -1};
	dirs['r'] = {0, 1};
	dirs['u'] = {-1, 0};
	dirs['d'] = {1, 0};
	cin >> n;
	cin >> pos.first >> pos.second;
	pos.first--; pos.second--;

	char lastChar = ' ';
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		arr[i] = s;
		for (int j = 0; j < n; j++) {
			int dx = dirs[s[j]].first;
			int dy = dirs[s[j]].second;
			nxt[i][j] = {-1, -1};
			if (i + dx < 0 || i + dx >= n || j + dy < 0 || j + dy >= n) {
				lastChar = s[j];
				continue;
			}
			nxt[i][j] = {i + dx, j + dy};
			in[i + dx][j + dy].insert({i, j});
		}
	}

	pair<int, int> lst = {-1, -1};
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (nxt[i][j].first == -1) lst = {i, j};
	if (lst.first == -1) {
		cout << "impossible" << endl;
		return;
	}


	while (pos.first < lst.first) {
		res += 'd';
		pos.first += 1;
	}
	while (pos.first > lst.first) {
		res += 'u';
		pos.first -= 1;
	}
	while (pos.second < lst.second) {
		res += 'r';
		pos.second += 1;
	}
	while (pos.second > lst.second) {
		res += 'l';
		pos.second -= 1;
	}

	dfs(pos);

	bool allExplored = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			allExplored &= explored[i][j];
		}
	}
	res.pop_back();
	if (cycle || !allExplored || res.empty() || lastChar != res[res.size() - 1]) {
		cout << "impossible" << endl;
		return;
	}

	vector<pair<int, char>> moves;
	int cnt = 1;
	for (int i = 1; i < res.size(); i++) {
		if (res[i] != res[i - 1]) {
			moves.push_back({cnt, res[i - 1]});
			cnt = 0;
		}
		cnt++;
	}
	moves.push_back({cnt, res[res.size() - 1]});
	cout << moves.size() << endl;
	for (auto p : moves) cout << p.first << " " << p.second << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	solve();
	return 0;
}
