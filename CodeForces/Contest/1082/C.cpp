#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n;
string s;

array<int, 4> conquer(int l, int r) {
	if (r < l) return {0, 0, 0, 0};
	if (l == r) {
		if (s[l] == '(') return {1, 0, 0, 0};
		else return {0, 0, 0, 1};
	}

	int mid = (l + r) / 2;
	auto a = conquer(l, mid);
	auto b = conquer(mid + 1, r);
	array<int, 4> res = {0, 0, 0, 0};
	for (int i = 0; i < 4; i++) {
		int sa = 0;
		int sb = 0;
		for (int j = 0; j < 4; j++) {
			if ((j & 2) == (i & 2)) sa += a[j];
			if ((j & 1) == (i & 1)) sb += b[j];
		}
		sa %= mod;
		sb %= mod;
		res[i] += sa * sb % mod + a[i] + b[i];
		res[i] %= mod;
	}
	return res;
}

void solve() {
	cin >> n >> s;
	int ans = 0;
	auto a = conquer(0, n - 1);
	ans += a[0] + a[2];
	ans %= mod;

	string s2 = "";
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt -= s[i] == ')';

		if (cnt > 0) s2 += s[i];

		cnt += s[i] == '(';
	}

	s = s2;

	a = conquer(0, s.size() - 1);
	ans += a[1] + a[3];
	ans %= mod;

	cout << ans << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
