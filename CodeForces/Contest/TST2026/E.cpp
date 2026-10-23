#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
	int n, k;
	cin >> n >> k;
	int i = 1;
	int cnt = 0;
	vector<int> v1, v2;
	while (i < 32000000 && cnt < k && i * i <= n) {
		if (!(n % i)) {
			cnt++;
			v1.push_back(i);
			if (i * i != n) v2.push_back(n / i);
		}
		i++;
	}
	reverse(v2.begin(), v2.end());
	if (k > v1.size() + v2.size()) cout << -1 << endl;
	else if (k > v1.size()) cout << v2[k - v1.size() - 1] << endl;
	else cout << v1[k - 1] << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
