#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
int newInd[200005];
bool isZero[200005];
int p[200005];
pair<int, int> power[200005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> power[i].first;
		power[i].second = i;
	}
	sort(power, power + n);
	p[0] = n;
	newInd[n] = n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++) {
		newInd[power[i].second] = i;
	}
	int ptr = n;
	int ans = 0;
	int bestCnt = 0;
	for (int i = 1; i <= n / 2 + (n % 2); i++) {
		// i is the number of mushrooms used
		isZero[newInd[p[i - 1]]] = true;
		if (i != 1 && newInd[p[i - 1]] >= ptr) ptr--;
		isZero[n] = false;
		while (isZero[ptr]) ptr--;
		ptr--;
		while (isZero[ptr]) ptr--;
		if (power[ptr].first * i > ans) {
			ans = power[ptr].first * i;
			bestCnt = i;
		}
	}
	cout << ans << " " << bestCnt << endl;
	for (int i = 0; i <= n; i++) {
		newInd[i] = 0;
		isZero[i] = 0;
		p[i] = 0;
		power[i] = {0, 0};
	}
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
