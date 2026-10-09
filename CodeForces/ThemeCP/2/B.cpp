#include <bits/stdc++.h>
using namespace std;

long long n, k;

void solve() {
	cin >> n >> k;
	if (n < 60 && (1ll << (n - 1)) < k) {
		cout << -1 << endl;
		return;
	}
	k--;
	vector<long long> f;
	vector<long long> b;
	for (long long i = 1; i <= n; i++) {
		long long cnt = -1;
		for (long long i = 1; i <= k; i *= 2, cnt++);
		if (cnt < n - 1 - i) f.push_back(i);
		else {
			k -= (1ll << cnt);
			b.push_back(i);
		}
	}
	for (int i = b.size() - 1; i >= 0; i--) f.push_back(b[i]);
	for (int i : f) cout << i << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}//