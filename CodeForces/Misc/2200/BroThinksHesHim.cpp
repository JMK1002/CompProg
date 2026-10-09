#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

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
		return (a + b) % mod;
	}

	T query(int l, int r) {
		if (r < l) return 1;
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

string s;
int n, q;
tree<long long> pre[2];
tree<long long> suff[2];

long long binpow(int a, int b) {
	long long run = a;
	long long res = 1;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;
		run *= run;
		run %= mod;
		b >>= 1;
	}
	return res;
}

long long cont(int ind) {
	bool val = s[ind - 1] - '0';
	long long res = 0;
	res += pre[!val].query(1, ind) * suff[val].query(ind, ind) % mod;
	res += suff[!val].query(ind, n) * pre[val].query(ind, ind) % mod;
	res %= mod;
	return res;
}

void solve() {
	cin >> s >> q;
	n = s.size();

	for (int i = 0; i < 2; i++) {
		pre[i] = tree<long long>(n);
		suff[i] = tree<long long>(n);
	}

	for (int i = 0; i < n; i++) {
		bool val = s[i] - '0';
		pre[val].update(i + 1, binpow(2, i));
		suff[val].update(i + 1, binpow(2, n - i - 1));
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += cont(i);
		ans %= mod;
	}
	ans *= 499122177;
	ans %= mod;
	ans += binpow(2, n) - 1;
	ans %= mod;

	while (q--) {
		int ind;
		cin >> ind;
		ans -= cont(ind);
		pre[s[ind - 1] - '0'].update(ind, 0);
		suff[s[ind - 1] - '0'].update(ind, 0);
		s[ind - 1] = (s[ind - 1] == '0') ? '1' : '0';
		pre[s[ind - 1] - '0'].update(ind, binpow(2, ind - 1));
		suff[s[ind - 1] - '0'].update(ind, binpow(2, n - ind));
		ans += cont(ind);
		ans %= mod;
		ans += mod;
		ans %= mod;
		cout << ans << " ";
	}
	cout << endl;
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