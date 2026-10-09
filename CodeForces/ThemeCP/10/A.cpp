#include <bits/stdc++.h>
using namespace std;

#define int long long

int q(int a, int b) {
	cout << "? " << a << " " << b << endl;
	cout.flush();
	int res;
	cin >> res;
	return res;
}

void solve() {
	int low = 1;
	int high = 999;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		int res = q(1, mid);
		if (res == mid + 1) high = mid;
		else low = mid;
	}
	cout << "! " << high << endl;
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
