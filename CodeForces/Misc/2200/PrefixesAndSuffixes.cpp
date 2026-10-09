#include <iostream>
using namespace std;
int cnt[700];
void solve() {
	int n;
	string a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[n - 1 - i]) swap(a[i], b[n - 1 - i]);
		int v = 26 * (a[i] - 'a') + (b[n - i - 1] - 'a');
		cnt[v]++;
	}
	int asdf = 0;
	int basdf = 0;
	for (int i = 0; i < 700; i++) if (cnt[i] & 1) {
		asdf++;
		basdf += (i % 27 == 0);
	}
	if ((n & 1) && asdf == 1 && basdf == 1 || (n % 2 == 0) && asdf == 0) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i < 700; i++) cnt[i] = 0;
	}
	return 0;
}