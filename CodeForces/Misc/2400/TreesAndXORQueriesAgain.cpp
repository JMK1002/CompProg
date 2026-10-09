#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int b = 20;

struct basis {
	int arr[b];

	basis() {
		for (int i = 0; i < b; i++) arr[i] = 0;
	}

	int getXi(int x) {
		for (int i = b - 1, j = (1 << (b - 1)); i >= 0; i--, j >>= 1) {
			if (x & j) x ^= arr[i];
		}
		return x;
	}

	bool check(int x) {
		return getXi(x) == 0;
	}

	void modify(int x) {
		int xi = getXi(x);
		int k = -1;
		for (int i = 0, j = 1; i < b; i++, j <<= 1) {
			if (j & xi) k = i;
		}
		arr[k] = xi;
	}

	bool update(int x) {
		if (check(x)) return false;
		modify(x);
		return true;
	}

	void merge(basis* ba) {
		for (int i = 0; i < b; i++) {
			this->update(ba->arr[i]);
		}
	}
};

// bool brute(int *a, int n, int targ) {
// 	for (int i = 0; i < (1 << n); i++) {
// 		int r = 0;
// 		for (int k = 0, j = 1; j < (1 << n); k++, j <<= 1) {
// 			r ^= a[k] * (bool) (i & j);
// 		}
// 		if (r == targ) return true;
// 	}
// 	return false;
// }

int n;
int arr[200005];
set<int> adj[200005];
pair<int, int> times[200005];
vector<int> interestingNodes[200005];
basis bases[200005];
int par[200005][b];
int t = 0;

void dfs(int v, int p) {
	times[v].first = t++;
	par[v][0] = p;
	for (int i = 1; i < b; i++) par[v][i] = par[par[v][i - 1]][i - 1];
	for (int e : adj[v]) {
		if (e == p) continue;
		dfs(e, v);
	}
	times[v].second = t++;
}

void dfs2(int v) {
	if (!bases[par[v][0]].check(arr[v])) {
		for (int i = 0; i < b; i++) bases[v].arr[i] = bases[par[v][0]].arr[i];
		bases[v].modify(arr[v]);
	}
	else {

	}

	for (int e : adj[v]) {
		if (e == par[v][0]) continue;
		dfs2(e);
	}

	
}

bool isAncestor(int a, int b) {
	return times[a].first < times[b].first && times[a].second > times[b].second;
}

int lca(int a, int b) {
	if (isAncestor(a, b)) return a;
	if (isAncestor(b, a)) return b;

	int res = a;
	for (int i = b - 1; i >= 0; i--) {
		if (!isAncestor(par[res][i], b)) res = par[res][i];
	}
	return par[res][0];
}

int main() {
	cin >> n;
	// for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	dfs(0, 0);


	return 0;
}