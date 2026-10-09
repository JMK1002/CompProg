#include <bits/stdc++.h>
using namespace std;

int n;
int p[4005];
int inv[4005];

bool op(int i, int j) {
	cout << "? " << i << " " << j << endl;
	cout.flush();
	int x, y;
	cin >> x >> y;
	if (min(x, y) == min(i, j) && max(x, y) == max(i, j)) {
		swap(p[i], p[j]);
		inv[p[i]] = i;
		inv[p[j]] = j;
		return true;
	}
	else {
		swap(p[n - i + 1], p[n - j + 1]);
		inv[p[n - i + 1]] = n - i + 1;
		inv[p[n - j + 1]] = n - j + 1;
		return false;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		inv[p[i]] = i;
	}
	for (int i = 1; i <= n / 2; i++) {
		while (!(inv[n - i + 1] == n - i + 1 && inv[i] == i)) {
			bool a = inv[n - i + 1] == n - i + 1;
			bool b = inv[i] == i;
			if (a && a == b) {
				op(i, n - i + 1);
			}
			else if (b) {
				op(inv[n - i + 1], n - i + 1);
			}
			else {
				op(inv[i], i);
			}
		}
	}
	cout << "!" << endl;
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