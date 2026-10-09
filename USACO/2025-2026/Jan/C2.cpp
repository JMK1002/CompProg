#include <bits/stdc++.h>
using namespace std;

long long n;
long long arr[200005];
long long ord[200005];

void solve() {
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		ord[i] = i;
	}
	sort(ord + 1, ord + (n + 1), [&] (long long a, long long b) {
		if (arr[a] > arr[b]) return true;
		return false;
	});

	long long ans = 0;
	long long i = 1;
	long long l = 0;
	long long r = 0;
	vector<long long> vals;
	while (i <= n) {
		long long x = i;
		while (i <= n && arr[ord[x]] == arr[ord[i]]) {
			vals.push_back(ord[i]);
			i++;
		}
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
	cout << ans << endl;
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