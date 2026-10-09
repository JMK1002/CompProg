#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

void solve() {
	long long n, l, r, k;
	cin >> n >> l >> r >> k;

	if (n == 2) {
		cout << -1 << endl;
		return;
	}

	long long a = 1;
	while (a <= l) {
		a <<= 1;
	}

	if (n % 2 == 1) {
		cout << l << endl;
	}
	else {
		if (a > r) {
			cout << -1 << endl;
			return;
		}

		if (k == n || k == n - 1) {
			cout << a << endl;
		}
		else cout << l << endl;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}