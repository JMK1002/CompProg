#include <iostream>
using namespace std;

int n;
int d[200005];
int bot[200005];
int top[200005];
int diff[200005];
int suffMin[200005];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> d[i];
	for (int i = 0; i < n; i++) cin >> bot[i] >> top[i];
	// int mx = 0;
	// for (int i = 0; i < n; i++) {
	// 	mx = max(mx, bot[i]);
	// 	bot[i] = mx;
	// }
	// int mn = 2000000000;
	// for (int i = n - 1; i >= 0; i--) {
	// 	mn = min(mn, top[i]);
	// 	top[i] = mn;
	// }

	int h = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) h++;
		diff[i] = top[i] - h;
	}
	int mn = 2000000000;
	for (int i = n - 1; i >= 0; i--) {
		mn = min(mn, diff[i]);
		suffMin[i] = mn;
	}

	int added = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] != -1) continue;
		if (suffMin[i] - added > 0) {
			added++;
			d[i] = 1;
		}
		else {
			d[i] = 0;
		}
	}

	h = 0;
	for (int i = 0; i < n; i++) {
		if (d[i] == 1) h++;
		if (h > top[i] || h < bot[i]) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < n; i++) cout << d[i] << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= n; i++) {
			d[i] = 0;
			top[i] = 0;
			bot[i] = 0;
			diff[i] = 0;
			suffMin[i] = 0;
		}
	}
	return 0;
}