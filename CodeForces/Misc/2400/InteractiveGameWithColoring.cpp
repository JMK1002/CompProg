#include <iostream>
#include <set>
using namespace std;

int n;
int p[102];
int col[102];
set<int> adj[102];

void dfs2(int v) {
	for (int i : adj[v]) {
		col[i] = 1 - col[v];
		dfs2(i);
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i]--;
		adj[p[i]].insert(i);
	}
	bool two = true;
	for (int i = 0; i < n; i++) two &= adj[i].size() != 2;
	int k = 2 + (!two);
	if (two) {
		cout << 2 << endl;
		dfs2(0);
		for (int i = 0; i < n; i++) cout << col[i] + 1 << " ";
		cout << endl;
		fflush(stdout);
		while () {
			int x;
			cin >> x;
			if (x == 1 || -1) return 0;
			for (int i = 0; i < k; i++) {

			}
		}
	}
	return 0;
}