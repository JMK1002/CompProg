#include <bits/stdc++.h>
using namespace std;

void solve() {
	int a, b;
	int l1, r1, l2, r2;
	cin >> a >> b;
	a--; b--;
	l1 = a / 6; l2 = b / 6; r1 = a % 6; r2 = b % 6;
	int amnt = abs(l1 - l2) + min(max(r1, r2) - min(r1, r2), 6 - (max(r1, r2) - min(r1, r2)));
	cout << amnt << endl;
	cout << a + 1 << " ";
	while (l2 < l1) {
		a -= 6;
		l1--;
		cout << a + 1 << " ";
	}
	while (l2 > l1) {
		a += 6;
		l1++;
		cout << a + 1 << " ";
	}

	if (max(r1, r2) - min(r1, r2) < 6 - (max(r1, r2) - min(r1, r2))) {
		while (r1 > r2) {
			a--;
			r1--;
			cout << a + 1 << " ";
		}
		while (r2 > r1) {
			a++;
			r1++;
			cout << a + 1 << " ";
		}
	}
	else {
		if (r1 > r2) {
			while (r1 != r2) {
				r1++;
				r1 %= 6;
				a = 6 * l1 + r1;
				cout << a + 1 << " ";
			}
		}
		else {
			while (r1 != r2) {
				r1--;
				r1 += 6;
				r1 %= 6;
				a = 6 * l1 + r1;
				cout << a + 1 << " ";
			}
		}
	}
	cout << endl;
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