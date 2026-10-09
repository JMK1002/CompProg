#include <bits/stdc++.h>
using namespace std;

int n;
int arr[200005];

void solve() {
	cin >> n;
	int mn = 1000000000;
	bool ans = true;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] >= mn * 2) ans = false;
		mn = min(arr[i], mn);
	}
	if (ans) cout << "YES" << endl;
	else cout << "NO" << endl;
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