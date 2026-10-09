#include <bits/stdc++.h>
using namespace std;

const string cols[] = {
	"BG",
	"BR",
	"BY",
	"GR",
	"GY",
	"RY"
};

int n, q;
string arr[200005];
map<string, vector<int>> inds;

string getOp(string a) {
	int ind = -1;
	for (int i = 0; i < 6; i++) if (cols[i] == a) ind = i;
	return cols[5 - ind];
}

void solve() {
	cin >> n >> q;
	for (string s : cols) inds[s].push_back(-1e8);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		inds[arr[i]].push_back(i);
	}
	for (string s : cols) inds[s].push_back(1e8);
	while (q--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		string op = getOp(arr[u]);
		if (op != arr[v]) {
			cout << abs(u - v) << endl;
			continue;
		}
		if (u > v) swap(u, v);
		int mn = 1e9;
		for (string s : cols) {
			if (s == arr[u] || s == arr[v]) continue;
			int ind = lower_bound(inds[s].begin(), inds[s].end(), u) - inds[s].begin();
			if (inds[s][ind] < v) {
				mn = abs(u - v);
			}
			else {
				mn = min(mn, abs(u - inds[s][ind]) + abs(v - inds[s][ind]));
				mn = min(mn, abs(u - inds[s][ind - 1]) + abs(v - inds[s][ind - 1]));
			}
		}
		if (mn > 3 * n) {
			cout << -1 << endl;
		}
		else {
			cout << mn << endl;
		}
	}

	inds.clear();
	for (int i = 0; i <= n; i++) arr[i].clear();
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