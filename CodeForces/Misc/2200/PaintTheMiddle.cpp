#include <iostream>
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

int n;
int arr[200005];
int lst[200005];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		lst[arr[i]] = i;
	}
	tree<int> mx(n);
	for (int i = 1; i <= n; i++) {
		mx.update(i, lst[arr[i]]);
	}

	int i = 1;
	int ans = n;
	while (i <= n) {
		int r = mx.query(i, i);
		int cnt = 1;
		while (r > i && mx.query(i, r) > r) {
			cnt++;
			r = mx.query(i, r);
		}
		if (i == r) ans--;
		else ans -= cnt + 1;
		i = r + 1;
	}
	cout << ans << endl;
	return 0;
}