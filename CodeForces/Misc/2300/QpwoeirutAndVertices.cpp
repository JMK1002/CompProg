#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
struct tree {
	int n;
	vector<T> t;
	tree() : n(0) {}
	tree(int n) : n(n) {
		t = vector<T>(4 * (n + 1));
	}

	// Change depending on T
	T op(T a, T b) {
		return max(a, b);
	}

	T query(int l, int r) {
		return query(l, r, 1, 1, n);
	}

	void update(int ind, T val) {
		update(ind, val, 1, 1, n);
	}

	T query(int l, int r, int v, int tl, int tr) {
		if (l == tl && r == tr) return t[v];
		else {
			int tm = (tl + tr) / 2;
			if (l > min(tm, r)) {
				return query(max(tm + 1, l), r, v * 2 + 1, tm + 1, tr);
			}
			if (max(tm + 1, l) > r) {
				return query(l, min(tm, r), v * 2, tl, tm);
			}
			return op(
				query(l, min(tm, r), v * 2, tl, tm),
				query(max(tm + 1, l), r, v * 2 + 1, tm + 1, tr)
			);
		}
	}

	void update(int ind, T val, int v, int tl, int tr) {
		if (tl == tr) t[v] = val;
		else {
			int tm = (tl + tr) / 2;
			if (ind <= tm) {
				update(ind, val, v * 2, tl, tm);
			}
			else {
				update(ind, val, v * 2 + 1, tm + 1, tr);
			}
			t[v] = op(t[v * 2], t[v * 2 + 1]);
		}
	}
};

int n, m, q;
int col[100005];
vector<int> inv[100005];
int tah[100005];

void combine(int a, int b, int t) {
	a = col[a];
	b = col[b];
	if (a == b) return;
	if (inv[a].size() < inv[b].size()) swap(a, b);
	for (int i : inv[b]) {
		col[i] = a;
		if (col[i + 1] == col[i]) tah[i] = min(t, tah[i]);
		if (col[i - 1] == col[i]) tah[i - 1] = min(t, tah[i - 1]);
		inv[a].push_back(i);
	}
	inv[b].clear();
}

void solve() {
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		col[i] = i;
		inv[i].push_back(i);
		tah[i] = 1e9;
	}
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		combine(u, v, i);
	}
	// for (int i = 1; i <= n - 1; i++) cout << tm[i] << " ";
	// cout << endl;

	tree<int> t(n);
	for (int i = 1; i <= n; i++) t.update(i, tah[i]);
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r) {
			cout << 0 << " ";
			continue;
		}
		cout << t.query(l, r - 1) << " ";
	}
	cout << endl;

	for (int i = 0; i <= n + 1; i++) {
		col[i] = 0;
		inv[i].clear();
		tah[i] = 0;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}