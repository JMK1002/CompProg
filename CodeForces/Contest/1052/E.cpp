#include <bits/stdc++.h>
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
		return a + b;
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

int n;
int arr[300005];
int ans[300005];
vector<int> inds[300005];

void solve() {
	cin >> n;
	tree<int> t(n + 3);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		inds[arr[i]].push_back(i);
		t.update(i, 1);
	}
	for (int i = 0; i <= n; i++) {
		for (int j : inds[i]) t.update(j, 0);
		if (inds[i].empty()) {
			ans[n] = max(ans[n], t.query(1, n));
			continue;
		}
		ans[inds[i][0] - 1] = max(ans[inds[i][0]], t.query(1, inds[i][0]));
		ans[n] = max(ans[n], t.query(inds[i].back(), n));
		for (int j = 0; j < inds[i].size() - 1; j++) {
			ans[inds[i][j + 1] - 1] = max(ans[inds[i][j + 1]], t.query(inds[i][j], inds[i][j + 1]));
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		ans[i] = 0;
		inds[i].clear();
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}