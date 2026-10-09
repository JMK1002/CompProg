#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, q;
long long arr[200005];

long long binpow(long long a, long long b) {
	long long res = 1;
	long long run = a;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;
		b >>= 1;
		run *= run;
		run %= mod;
	}
	return res % mod;
}

void solve() {
	string s;
	cin >> n >> q >> s;
	long long cnt = 0;
	for (long long i = 1; i <= n; i++) {
		arr[i] = s[i - 1] == '1' ? 1 : -1;
		cnt += arr[i] == -1;
	}

	while (q--) {
		long long ind;
		cin >> ind;
		arr[ind] *= -1;
		if (arr[ind] == -1) cnt++;
		else cnt--;
		long long v = (n * (n + 1) % mod - 4 * n * cnt % mod + 4 * cnt * cnt % mod - 2);
		v %= mod;
		if (n < 4) {
			for (long long j = 0; j < 4 - n; j++) v /= 2;
		}
		else v *= binpow(2, n - 4);
		v %= mod;
		cout << v << endl;
	}
}

int main() {
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

// ! I misread the problem and am crying rn

// pair<long long, long long> t[1000000]; // {max, min} seg tree
// long long lazy[2000000];

// void push(long long v) {
// 	t[v].first += lazy[v];
// 	t[v].second += lazy[v];
// 	lazy[v * 2] += lazy[v];
// 	lazy[v * 2 + 1] += lazy[v];
// 	lazy[v] = 0;
// }

// pair<long long, long long> op(pair<long long, long long> a, pair<long long, long long> b) {
// 	return {max(a.first, b.first), min(a.second, b.second)};
// }

// void set(long long v, long long tl, long long tr, long long ind, long long val) {
// 	if (tl > tr || tl > ind || tr < ind) return;
// 	else if (tl == tr) {
// 		push(v);
// 		t[v] = {val, val};
// 	}
// 	else {
// 		push(v);
// 		long long tm = (tl + tr) / 2;
// 		set(v * 2, tl, tm, ind, val);
// 		set(v * 2 + 1, tm + 1, tr, val, ind);
// 		t[v] = op(t[v * 2], t[v * 2 + 1]);
// 	}
// }

// void add(long long v, long long tl, long long tr, long long l, long long r, long long val) {
// 	if (tl > l || tr < r || l > r || tl > r) return;
// 	else if (tl == l && tr == r) {
// 		lazy[v] += val;
// 		push(v);
// 	}
// 	else {
// 		push(v);
// 		long long tm = (tl + tr) / 2;
// 		add(v * 2, tl, tm, l, min(tm, r), val);
// 		add(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r, val);
// 		t[v] = op(t[v * 2], t[v * 2 + 1]);
// 	}
// }

// pair<long long, long long> query(long long v, long long tl, long long tr, long long l, long long r) {
// 	if (tl > l || tr < r || l > r || tl > r) return {0, 10000000};
// 	else if (tl == l && tr == r) {
// 		push(v);
// 		return t[v];
// 	}
// 	else {
// 		push(v);
// 		long long tm = (tl + tr) / 2;
// 		return op(
// 			query(v * 2, tl, tm, l, min(tm, r)),
// 			query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r)
// 		);
// 	}
// }