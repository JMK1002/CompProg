#include <iostream>
#include <vector>
#include <map>
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
		return min(a, b);
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
int arr[200005];
int p[200005];
int lst[400005];
tree<int> mn;

void solve() {
	cin >> n;
	mn = tree<int>(n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		mn.update(i, arr[i]);
	}
	int ans = 0;
	for (int j = 1; j <= min(n, 100); j++) {
		for (int i = 0; i <= 2 * n; i++) lst[i] = -1;
		lst[n] = 0;
		for (int i = 1; i <= n; i++) {
			p[i] = p[i - 1] + (arr[i] >= j ? 1 : -1);
			if (lst[p[i] + n] != -1) {
				ans = max(ans, j - mn.query(lst[p[i] + n] + 1, i));
			}
			lst[p[i] + n] = i;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		p[i] = 0;
	}
	for (int i = 0; i <= 2 * n; i++) {
		lst[i] = 0;
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
	return 0;
}