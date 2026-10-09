#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int n;
int arr[200005];
int par[200005];
int sz[200005];
int srtd[200005];
bool pos[200005][2];
int inc, run;

int rt(int a) {
	int res = a;
	while (par[res] != res) res = par[res];
	while (par[a] != a) {
		par[a] = res;
		a = par[a];
	}
	return res;
}

void un(int a, int b) {
	int ra = rt(a);
	int rb = rt(b);

	inc -= (sz[ra] % 2 == 0 && pos[ra][0] || pos[ra][1]) || (sz[ra] % 2 == 1 && pos[ra][1]);
	inc -= (sz[rb] % 2 == 0 && pos[rb][0] || pos[rb][1]) || (sz[rb] % 2 == 1 && pos[rb][1]);
	run -= (sz[ra] + 1) / 2;
	run -= (sz[rb] + 1) / 2;

	if (rb < ra) swap(ra, rb);
	// ra is the first range
	if (sz[ra] % 2 == 1) swap(pos[rb][0], pos[rb][1]);

	if (sz[rb] < sz[ra]) swap(ra, rb);
	par[ra] = rb;
	sz[rb] += sz[ra];
	pos[rb][0] |= pos[ra][0];
	pos[rb][1] |= pos[ra][1];

	run += (sz[rb] + 1) / 2;
	inc += (sz[rb] % 2 == 0 && pos[rb][0] || pos[rb][1]) || (sz[rb] % 2 == 1 && pos[rb][1]);
}

void add(int ind) {
	int cnt = 0;
	run++;
	if (pos[ind][1]) inc++;
	if (ind != 0 && arr[ind - 1] >= arr[ind]) {
		un(ind, ind - 1);
		cnt++;
	}
	if (ind != n - 1 && arr[ind + 1] > arr[ind]) {
		un(ind, ind + 1);
		cnt++;
	}
}

void solve() {
	cin >> n;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	iota(par, par + n, 0);
	iota(srtd, srtd + n, 0);
	sort(srtd, srtd + n, [&] (int a, int b) {
		return arr[a] > arr[b];
	});
	for (int i = 0; i < n; i++) {
		if (arr[i] == mx) pos[i][1] = true;
		sz[i] = 1;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		add(srtd[i]);
		ans = max(ans, run + arr[srtd[i]] + mx - (inc == 0));
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		par[i] = 0;
		srtd[i] = 0;
		pos[i][0] = 0;
		pos[i][1] = 0;
		sz[i] = 0;
	}
	inc = 0; run = 0;
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