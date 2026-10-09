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

	void update(int ind) {
		update(ind, 1, 1, 1, n);
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
		if (tl == tr) t[v]++;
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

long long cntInv(int x) {
	int cnt = 1;
	map<int, int> mp;
	vector<int> v;
	for (int i = 0; i < n; i++) v.push_back(arr[i] ^ x);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		if (mp.find(v[i]) == mp.end()) mp[v[i]] = cnt++;
	}
	tree<int> t(n + 10);
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		t.update(mp[arr[i] ^ x]);
		ans += t.query(mp[arr[i] ^ x] + 1, n + 8);
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		// arr[i] = i;
	}
	long long base = cntInv(0);
	int ans = 0;
	// cout << cntInv(1) << endl;
	for (int i = 0, r = 1; i < 31; i++, r <<= 1) if (cntInv(r) < base) ans += r;
	cout << cntInv(ans) << " " << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}