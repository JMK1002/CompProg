#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[500005];
long long ord[500005];

pair<long long, long long> t[2000000];

void upd(long long v, long long tl, long long tr, long long ind, pair<long long, long long> val) {
	if (tl > tr || tl > ind || tr < ind) return;
	else if (tl == tr) {
		t[v] = val;
	}
	else {
		long long tm = (tl + tr) / 2;
		upd(v * 2, tl, tm, ind, val);
		upd(v * 2 + 1, tm + 1, tr, ind, val); 
		t[v].first = t[v * 2].first + t[v * 2 + 1].first;
		t[v].second = t[v * 2].second + t[v * 2 + 1].second;
	}
}

pair<long long, long long> gt(long long v, long long tl, long long tr, long long l, long long r) {
	if (tl > tr || l > r || tl > l || tr < r) return {0, 0};
	else if (tl == l && tr == r) {
		return t[v];
	}
	else {
		long long tm = (tl + tr) / 2;
		pair<long long, long long> a = gt(v * 2, tl, tm, l, min(tm, r));
		pair<long long, long long> b = gt(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r); 
		return {a.first + b.first, a.second + b.second};
	}
}


long long solve() {
	sort(ord + 1, ord + (n + 1), [&] (long long a, long long b) {
		if (arr[a] > arr[b]) return true;
		return false;
	});

	long long ans = 0;
	long long i = 1;
	vector<long long> vals;
	while (i <= n) {
		long long x = i;
		while (i <= n && arr[ord[x]] == arr[ord[i]]) {
			vals.push_back(ord[i]);
			i++;
		}
		sort(vals.begin(), vals.end());
		for (long long j = 0; j < vals.size(); j++) {
			long long ind = vals[j];
			long long lc = ind - 1 - gt(1, 1, n, 1, ind).first - gt(1, 1, n, 1, ind).second;
			long long rc = n - ind - gt(1, 1, n, ind, n).first - gt(1, 1, n, ind, n).second - (vals.size() - j - 1);
			if (lc <= rc) upd(1, 1, n, ind, {1, 0});
			else upd(1, 1, n, ind, {0, 1});
			ans += min(lc, rc);
		}
		vals.clear();
	}
	return ans;
}

long long solve2() {
	long long ans = 0;
	long long cnt = 0;
	long long tot = 0;
	long long run = 0;
	vector<long long> inds;
	for (long long i = 1; i <= n; i++) tot += arr[i];
	for (long long i = 1; i <= n; i++) {
		if (!arr[i]) continue;
		inds.push_back(i);
		run += i;
	}
	run -= tot * (tot + 1) / 2;
	ans = run;
	for (long long i = 0; i < tot; i++) {
		run -= inds[tot - i - 1] - (tot - i);
		run += n - inds[tot - i - 1] - (i);
		ans = min(ans, run);
	}
	return ans;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	long long cnt = 0;
	cout <<"";

	while (t--) {

		cin >> n;
		// n=15;
		bool has = false;
		for (long long i = 1; i <= n; i++) {
			cin >> arr[i];
			if (arr[i] >= 2) has = true;
			// arr[i] = (bool) ((1 << (i - 1)) & cnt);
			// arr[i] = min(i, n - i + 1);
			ord[i] = i;
		}
		long long x = solve();

		// if (x != y) {
		// 	for (long long i = 1; i <= n; i++) cout << arr[i] << " ";
		// 	cout << endl;
		// }

		if (has) cout << x << endl;
		else cout << solve2() << endl;
		// cout << y << endl;
		for (long long i = 1; i <= n; i++) {
			upd(1, 1, n, i, {0, 0});
			arr[i] = 0;
			ord[i] = 0;
		}
		cnt++;
	}
	return 0;
}