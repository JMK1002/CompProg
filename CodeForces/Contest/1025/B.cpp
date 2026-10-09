#include <iostream>
using namespace std;

int calc(int n, int m) {
	int ans = 0;
	while (n != 1) {
		n = (n - n / 2);
		ans++;
	}
	while (m != 1) {
		m = (m - m / 2);
		ans++;
	}
	return ans;
}

void solve() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	int ans = min(calc(a, m), calc(n - a + 1, m));
	ans = min(ans, min(calc(n, b), calc(n, m - b + 1)));
	cout << ans + 1 << endl;
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