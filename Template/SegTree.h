template <typename T>
struct segtree {
	int n;
	vector<T> t;
	segtree() : n(0) {}
	segtree(int n) : n(n) {
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