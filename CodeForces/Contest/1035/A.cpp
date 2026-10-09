#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void solve() {
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if ((a ^ 1) == b && a > b) {
		cout << y << endl;
		return;
	}

	if (a > b) {
		cout << -1 << endl;
		return;
	}

	if (x <= y) {
		cout << (b - a) * x << endl;
		return;
	}
	int ans = 0;
	while (a != b) {
		if (a % 2 == 0) {
			ans += y;
		}
		else {
			ans += x;
		}
		a++;
	}
	cout << ans << endl;
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