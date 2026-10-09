#include <bits/stdc++.h>
using namespace std;

int arr[400005];
int cnt[400005];

void solve() {
	int n;
	cin >> n;
	set<int> s;
	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
		s.insert(arr[i]);
	}
	int evev = 0;
	int evod = 0;
	int od = 0;
	for (int i : s) {
		if (cnt[i] % 2 == 1) od++;
		else if (cnt[i] / 2 % 2 == 0) evev++;
		else evod++;
	}
	if (od == 0) cout << evod * 2 + od + (evev / 2 * 4) << endl;
	else cout << evod * 2 + evev * 2 + od << endl;
	for (int i = 0; i < 2 * n; i++) {
		cnt[arr[i]] = 0;
		arr[i] = 0;
	}
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