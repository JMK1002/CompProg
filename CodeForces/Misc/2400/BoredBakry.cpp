#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int b = 23;
const int MAXN = 1000006;

int n;
int arr[MAXN];
int pre[b + 1][MAXN];
map<int, vector<int>> frst[2][b + 1];
int valid[b];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 0, msk = 1; j < b; j++, msk <<= 1) {
			pre[j][i] = pre[j][i - 1] ^ (arr[i] & msk);
		}
	}
	for (int i = 1; i <= n; i++) for (int j = b - 1; j >= 0; j--) pre[j][i] |= pre[j + 1][i];

	int ans = 0;
	for (int j = 0, msk = 1; j < b; j++, msk <<= 1) {
		frst[0][j][pre[j][0]].push_back(0);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0, msk = 1; j < b; j++, msk <<= 1) {
			if (!(arr[i] & msk)) valid[j] = i;
		}

		for (int j = b - 1, msk = 1 << (b - 1); j >= 0; j--, msk >>= 1) {
			if (valid[j] == i) continue;
			int ind = lower_bound(frst[i % 2][j + 1][pre[j][i]].begin(), frst[i % 2][j + 1][pre[j][i]].end(), valid[j]) - frst[i % 2][j + 1][pre[j][i]].begin();
			if (ind == frst[i % 2][j + 1][pre[j][i]].size()) continue;
			int v = frst[i % 2][j + 1][pre[j][i]][ind];
			ans = max(ans, i - v);
		}

		for (int j = 0, msk = 1; j < b; j++, msk <<= 1) {
			frst[i % 2][j][pre[j][i]].push_back(i);
		}
	}

	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		for (int j = 0; j < b; j++) {
			pre[j][i] = 0;
			frst[i % 2][j][pre[j][i]].clear();
			valid[j] = 0;
		}
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
