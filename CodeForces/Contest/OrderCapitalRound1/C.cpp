#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> pts[200005];
pair<int, int> x[200005];
pair<int, int> y[200005];
pair<bool, bool> quad[200005];
vector<int> st[2][2];
bool explored[200005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> pts[i].first >> pts[i].second;
		x[i].first = pts[i].first;
		y[i].first = pts[i].second;
		x[i].second = i;
		y[i].second = i;
	}
	sort(x, x + n);
	sort(y, y + n);
	for (int i = 0; i < n / 2; i++) quad[x[i].second].first = true;
	for (int i = 0; i < n / 2; i++) quad[y[i].second].second = true;
	for (int i = 0; i < n; i++) {
		st[quad[i].first][quad[i].second].push_back(i+1);
	}
	for (int i = 0; i < st[0][0].size(); i++) {
		cout << st[0][0][i] << " " << st[1][1][i] << endl;
	}
	for (int i = 0; i < st[1][0].size(); i++) {
		cout << st[1][0][i] << " " << st[0][1][i] << endl;
	}

	for (int i = 0; i <= n; i++) {
		pts[i] = {0, 0};
		x[i] = {0, 0};
		y[i] = {0, 0};
		quad[i] = {0, 0};
		explored[i] = false;
	}
	st[0][0].clear();
	st[0][1].clear();
	st[1][0].clear();
	st[1][1].clear();
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