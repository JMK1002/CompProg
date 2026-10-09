#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;

long long n, d;
bool coach[1000006];
long long arr[1000006];
long long t[8000002];
long long lazy[8000002];

void psh(long long v) {
	if (lazy[v] == 1) return;
	lazy[v * 2] *= lazy[v];
	lazy[v * 2] %= mod;
	lazy[v * 2 + 1] *= lazy[v];
	lazy[v * 2 + 1] %= mod;
	
	t[v * 2] *= lazy[v];
	t[v * 2] %= mod;
	t[v * 2 + 1] *= lazy[v];
	t[v * 2 + 1] %= mod;

	lazy[v] = 1;
}

void upd(long long v, long long tl, long long tr, long long ind, long long val) {
	if (tl > tr || tl > ind || tr < ind) return;
	else if (tl == tr) {
		psh(v);
		t[v] = val;
	}
	else {
		psh(v);
		long long tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, ind, val);
		upd(v * 2 + 1, tm + 1, tr, ind, val); 
		t[v] = t[v * 2] + t[v * 2 + 1];
		t[v] %= mod;
	}
}

long long gt(long long v, long long tl, long long tr, long long l, long long r) {
	if (tl > tr || l > r || tl > l || tr < r) return 0;
	else if (tl == l && tr == r) {
		psh(v);
		return t[v];
	}
	else {
		psh(v);
		long long tm = (tl + tr) / 2;
		return 
			(gt(v * 2, tl, tm, l, min(tm, r)) +
			gt(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r)) % mod; 
	}
}

void twoTimes(long long v, long long tl, long long tr, long long l, long long r) {
	if (tl > tr || l > r || tl > l || tr < r) return;
    if (l == tl && r == tr) {
		psh(v);
		lazy[v] *= 2;
		lazy[v] %= mod;
		t[v] *= 2;
		t[v] %= mod;
    } 
	else {
		psh(v);
		long long tm = (tl + tr) / 2;
		twoTimes(v * 2, tl, tm, l, min(tm, r));
		twoTimes(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r); 
		t[v] = t[v * 2] + t[v * 2 + 1];
		t[v] %= mod;
    }
}

void solve() {
	cin >> n >> d;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i] >> coach[i];
	}
	long long l = 1;
	for (long long i = 1; i <= n; i++) {
		if (!coach[i]) {
			while (l < i && (!coach[l] || (arr[i] - arr[l] > d))) l++;
			if (l == i) continue;
			twoTimes(1, 1, n, l, i);
		}
		else {
			upd(1, 1, n, i, gt(1, 1, n, 1, i) + 1);
		}
	}
	long long ans = gt(1, 1, n, 1, n);
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cout << "";
	solve();
	return 0;
}