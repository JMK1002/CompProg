#include <iostream>
#include <set>
using namespace std;

int n, m;
bool explored[1000005];
long long cntCnts[40];
int smallest[1000005];

void solve() {
	cin >> n >> m;
	int mx = 0;
	for (int i = 2; i <= n; i++) {
		if (explored[i]) continue;
		int cnt = 0;
		long long v = i;
		while (v <= n) {
			explored[v] = true;
			cnt++;
			v *= i;
		}
		cntCnts[cnt]++;
		mx = max(cnt, mx);
	}
	for (int i = 37; i >= 2; i--) {
		for (int j = i; j <= m; j += i) smallest[j] = i;
	}
	long long ans = 0;
	int cnt = 0;
	for (int i = 1; i <= mx; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == 1) {
				cnt++;
				continue;
			}
			for (int k = i - 1; k >= 1; k--) {
				if (i * j % k != 0) continue;
				if (i * j / k > m) cnt++;
				break;
			}
		}
		ans += cntCnts[i] * cnt;
	}
	cout << ans + 1 << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}