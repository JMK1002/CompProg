#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
pair<int, int> arr[255];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << " ";
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << 0;
			else cout << 1;
		}
		cout << endl;
		cout.flush();
		int x;
		cin >> x;
		arr[i].first = x;
		arr[i].second = i;
	}
	sort(arr + 1, arr + n + 1);
	reverse(arr + 1, arr + n + 1);

	string s;
	for (int i = 1; i <= n; i++) {
		s += "0";
	}
	int mn = 1;
	for (int i = 1; i <= n; i++) {
		if (i != 1) {
			cout << "? " << arr[i].second << " " << s << endl;
			cout.flush();
			int x;
			cin >> x;
			if (x == 0) {
				continue;
			}
			else {
				for (int j = mn + 1; j < i; j++) s[arr[j].second - 1] = '1';
				int ind = i;
			}
		}
		s[arr[i].second - 1] = '1';
	}
	cout << "! " << s << endl;
}

signed main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
