#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int cnt[100005];
bool type[100005];
bool explored[100005];
set<int> radj[100005];
set<int> adj[100005];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;

	int trues[2] = {-1, -1};

	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (a == "set") type[i] = 1;
		if (b == "true") {
			trues[type[i]] = i;
		}
	}

	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		radj[v].insert(u);
		adj[u].insert(v);
	}
	for (int i = 0; i < n; i++) cnt[i] = adj[i].size();
	if (trues[0] != -1 && trues[1] == -1) {
		cout << -1 << endl;
		return 0;
	}

	vector<int> ans;
	for (int i = (trues[0] != -1) + (trues[1] != -1); i >= 0; i--) {
		int t = i % 2;
		queue<int> q;
		for (int j = 0; j < n; j++) {
			if (type[j] == t && cnt[j] == 0 && !explored[j] && trues[t] != j) {
				q.push(j);
			}
		}

		while (!q.empty()) {
			int v = q.front();
			q.pop();
			explored[v] = true;
			ans.push_back(v);
			for (int e : radj[v]) {
				cnt[e]--;
				if (type[e] == t && e != trues[t] && cnt[e] == 0 && !explored[e]) {
					q.push(e);
				}
			}
		}

		if (i != 0) {
			if (cnt[trues[t]] != 0) {
				cout << -1 << endl;
				return 0;
			}
			ans.push_back(trues[t]);
			explored[trues[t]] = true;
			for (int e : radj[trues[t]]) cnt[e]--;
		}
	}
	if (ans.size() != n) {
		cout << -1 << endl;
		return 0;
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans) cout << i + 1 << " ";
	cout << endl;
	return 0;
}
//