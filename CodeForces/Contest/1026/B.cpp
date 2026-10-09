#include <iostream>
#include <string>
using namespace std;


string s;

void solve() {
	cin >> s;
	int n = s.length();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') cnt++;
		else cnt--;
		if (cnt == 0 && i != n - 1) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
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