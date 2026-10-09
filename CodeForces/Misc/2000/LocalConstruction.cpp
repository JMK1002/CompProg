#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[200005];
vector<int> ind[40];
vector<int> adj[200005];
vector<int> curr;
vector<bool> added;
vector<int> topo;
int ans[200005];
bool explored[200005];

void addEdge(int a, int b) {
	if (a >= curr.size() || b >= curr.size() || a < 0 || b < 0) return;
	adj[curr[a]].push_back(curr[b]);
}

bool wasAdded(int a) {
	if (a >= curr.size() || a < 0) return false;
	return added[a];
}

void dfs(int v) {
	if (explored[v]) return;
	explored[v] = true;
	for (int e : adj[v]) dfs(e);
	topo.push_back(v);
	ans[v] = topo.size();
}

void solve() {
	cin >> n;
	int lstInd = -1;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == -1) lstInd = i;
		else ind[arr[i]].push_back(i);
		mx = max(mx, arr[i]);
	}
	arr[lstInd] = ++mx;
	ind[mx].push_back(lstInd);

	for (int i = mx; i >= 1; i--) {
		for (int j : ind[i]) curr.push_back(j);
		sort(curr.begin(), curr.end());

		added.clear();
		for (int j = 0; j < curr.size(); j++) {
			added.push_back(arr[curr[j]] == i);
		}

		if (curr.size() == 1) continue;

		int l = 0;
		int r = curr.size() - 1;

		while (l < curr.size() && added[l]) {
			if (i % 2 == 0) { // local max
				addEdge(l + 1, l);
			}
			else { // local min
				addEdge(l, l + 1);
			}
			l++;
		}

		while (r >= 0 && added[r]) {
			if (i % 2 == 0) { // local max
				addEdge(r - 1, r);
			}
			else { // local min
				addEdge(r, r - 1);
			}
			r--;
		}

		for (int j = l; j <= r; j++) {
			if (!added[j]) continue; // not currently added
			// ! TODO Don't forget to add the frickin edge cases of j = 0 or right side
			if (i % 2 == 0) { // local max
				addEdge(j - 1, j);
				if (wasAdded(j + 1)) addEdge(j, j + 1);
				else addEdge(j + 1, j);
			}
			else { // local min
				addEdge(j, j + 1);
				if (wasAdded(j - 1)) addEdge(j - 1, j);
				else addEdge(j, j - 1);
			}
		}
	}
	for (int i = 0; i < n; i++) dfs(i);
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;

	for (int i = 0; i <= n; i++) {
		ans[i] = 0;
		explored[i] = false;
		arr[i] = 0;
		adj[i].clear();
	}
	for (int i = 0; i < min(n + 2, 40); i++) ind[i].clear();
	curr.clear();
	added.clear();
	topo.clear();
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