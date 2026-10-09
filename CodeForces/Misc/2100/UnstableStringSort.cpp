#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, k;
int p[200005], invP[200005], q[200005], ans[200005];
bool explored[200005];

void solve() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		invP[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		q[i] = invP[x];
	}
	// for (int i = 1; i <= n; i++) cout << q[i] << " ";
	// cout << endl;
	int val = 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		explored[q[i]] = true;
		cnt += explored[i] + (q[i] < i);
		ans[i] = val;
		// cout << cnt << endl;
		if (cnt == i) val++;
	}
	if (val <= k) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		string s, res;
		for (int i = 1; i <= n; i++) {
			s += (char) (min(ans[i], 26ll) - 1 + 'a');
			res += " ";
		}
		for (int i = 1; i <= n; i++) {
			res[p[i] - 1] = s[i - 1];
		}
		cout << res << endl;
	}
	for (int i = 0; i <= n; i++) {
		p[i] = 0;
		q[i] = 0;
		invP[i] = 0;
		ans[i] = 0;
		explored[i] = 0;
	}


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
