#include <iostream>
using namespace std;

int s, k;
bool found[1000005];
bool temp[1000005];

void solve() {
	cin >> s >> k;
	if (s >= k * k) {
		if (s % k == 0) cout << k << endl;
		else cout << max(1, k - 2) << endl;
		return;
	}
	found[0] = true;
	for (int p = k; p > 0;) {
		for (int i = p; i <= s; i++) {
			temp[i] = found[i - p] || temp[i - p];
		}
		for (int i = 0; i <= s; i++) {
			found[i] = temp[i];
			temp[i] = false;
		}
		if (found[s]) {
			cout << p << endl;
			return;
		}
		p--;

		for (int i = s - p; i >= 0; i--) {
			temp[i] = found[i + p] || temp[i + p];
		}
		for (int i = 0; i <= s; i++) {
			found[i] = temp[i];
			temp[i] = false;
		}
		p--;
	}
	cout << 1 << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= k * k; i++) {
			temp[i] = 0;
			found[i] = 0;
		}
	}
	return 0;
}