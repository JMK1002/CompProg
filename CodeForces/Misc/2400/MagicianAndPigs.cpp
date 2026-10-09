#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 998244353;

int n;
pair<int, int> operations[800005];
vector<int> doubleOperationIndices;

int binpow(int a, int b) {
	int res = 1;
	int run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		res %= mod;
		run %= mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	cin >> n;
	int run = 0;
	int noDouble = 0;
	for (int i = 0; i < n; i++) {
		cin >> operations[i].first;
		if (operations[i].first != 3) cin >> operations[i].second;

		if (operations[i].first == 2) {
			run += operations[i].second;
			noDouble += operations[i].second;
		}
		if (operations[i].first == 3) {
			operations[i].second = run;
			run *= 2;
			doubleOperationIndices.push_back(i);
		}
		run = min(run, (long long) 1e10);
	}
	for (int i = 0; i < 32; i++) doubleOperationIndices.push_back(n);
	operations[n].first = 3;
	operations[n].second = (long long) 1e10;

	int ptr = 0;
	int doubleCnt = 0;
	int tot = 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		while (ptr < doubleOperationIndices.size() && (i > doubleOperationIndices[ptr] || operations[doubleOperationIndices[ptr]].second == 0)) ptr++;
		if (i == 0) tot = ptr;
		while (doubleCnt < doubleOperationIndices.size() && i > doubleOperationIndices[doubleCnt]) doubleCnt++;
		if (operations[i].first == 1) {
			int health = operations[i].second;
			health -= noDouble; // minimum amount subtracted by the end
			if (health <= 0) continue;
			int low = 0;
			int high = 2e9;
			while (high - low > 1) {
				int mid = (low + high) / 2;
				int subtractedAmount = 0;
				for (int j = ptr, msk = 1; j < ptr + 31; j++, msk <<= 1) {
					if (msk & mid) subtractedAmount += operations[doubleOperationIndices[j]].second;
					subtractedAmount = min(subtractedAmount, (long long) 1e10);
				}

				if (subtractedAmount >= health) high = mid;
				else low = mid;
			}
			ans += (low + 1) % mod * binpow(2, max(0ll, tot - doubleCnt)) % mod;
			ans %= mod;
		}
		else if (operations[i].first == 2) {
			noDouble -= operations[i].second;
		}
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) operations[i] = make_pair(0, 0);
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
