#include <bits/stdc++.h>
using namespace std;

int n;
map<int, int> mp;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x]++;
	}
	bool hasTwo = false;
	int last = -100;
	bool ans = false;
	for (pair<int, int> i : mp) {
		if (i.first != last + 1) {
			hasTwo = false;
		}
		if (i.second >= 2) {
			if (hasTwo) ans = true;
			else hasTwo = true;
		}
		if (i.second >= 4) ans = true;
		last = i.first;
	}
	cout << (ans ? "YES" : "NO") << endl;
	mp.clear();
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