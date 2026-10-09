#include <iostream>
#include <set>
using namespace std;

long long n, m;
long long arr[300005];
long long last[300005];
long long t[1500000];
set<long long> seen;

void clear(long long v, long long tl, long long tr) {
	if (tl > tr) return;
	else if (tl == tr) {
		t[v] = 0;
	}
	else {
		long long tm = (tl + tr) / 2;
		clear(v * 2, tl, tm);
		clear(v * 2 + 1, tm + 1, tr);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

void update(long long v, long long tl, long long tr, long long ind, long long val) {
	if (tl > tr || tl > ind || tr < ind) return;
	else if (tl == tr) {
		t[v] = val;
	}
	else {
		long long tm = (tl + tr) / 2;
		update(v * 2, tl, tm, ind, val);
		update(v * 2 + 1, tm + 1, tr, ind, val);
		t[v] = t[v * 2] + t[v * 2 + 1];
	}
}

long long query(long long v, long long tl, long long tr, long long l, long long r) {
	if (tl > tr || tl > l || tr < r || l > r) return 0;
	else if (tl == l && tr == r) {
		return t[v];
	}
	else {
		long long tm = (tl + tr) / 2;
		return query(v * 2, tl, tm, l, min(tm, r)) + 
			query(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> m;
	long long ans = 0;
	for (long long i = 1; i <= m; i++) last[i] = 0;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		seen.insert(arr[i]);

		if (last[arr[i]] != 0) {
			update(1, 1, n, last[arr[i]], 0);
		}
		update(1, 1, n, i, 1);

		if (last[arr[i]] == 0) {
			ans += m - 1;
		}
		else {
			ans += query(1, 1, n, max(1ll, last[arr[i]]), i - 1);
		}
		// cout << ans << " ";

		last[arr[i]] = i;
	}
	cout << ans << endl;
	return 0;
}