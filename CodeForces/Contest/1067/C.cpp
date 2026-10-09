#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long a[200005];
long long b[200005];
long long pre[200005];
// long long suff[200005];
long long preMn[200005];
long long suffMx[200005];
// long long suffMn[200005];

void solve() {
	cin >> n >> k;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = 1; i <= n; i++) cin >> b[i];
	for (long long i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + a[i];
		preMn[i] = min(preMn[i - 1], pre[i]);
	}
	suffMx[n] = pre[n];
	for (long long i = n - 1; i >= 0; i--) {
		suffMx[i] = max(suffMx[i + 1], pre[i]);
	}

	// for (long long i = n; i >= 1; i--) {
	// 	suff[i] = suff[i + 1] + a[i];
	// 	suffMn[i] = min(suffMn[i + 1], suff[i]);
	// }
	long long ans = -1e18;
	for (long long i = 1; i <= n; i++) {
		ans = max(ans, suffMx[i] + b[i] * (k % 2 == 1) - preMn[i - 1]);
	}
	cout << ans << endl;
	for (long long i = 0; i <= n + 1; i++) {
		a[i] = 0;
		b[i] = 0;
		pre[i] = 0;
		preMn[i] = 0;
		suffMx[i] = 0;
	}

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
}