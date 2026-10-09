#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) cnt += s[i] == 'Y';
	if (cnt <= 1) cout << "YES" << endl;
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