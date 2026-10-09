#include <bits/stdc++.h>
using namespace std;

int n;
string s;
bool arr[200005];
bool temp[200005];

void solve() {
	cin >> n >> s;
	s = "01" + s + "10";
	for (int i = 2; i < n + 2; i++) {
		arr[i] = (s[i] == '1') && (s[i - 1] == '0') && (s[i + 1] == '0');
	}
	bool works = true;
	bool hasTwo = true;
	int len = 0;
	for (int i = 2; i <= n + 2; i++) {
		if (s[i] == '1' && s[i - 1] == '1') {
			works &= hasTwo || !(len % 2);
			len = 0;
			hasTwo = false;
		}
		else if (s[i] == '0' && s[i - 1] == '1') {
			len++;
		}
		else if (s[i] == '0' && s[i - 1] == '0') {
			hasTwo = true;
		}
	}
	if (works) cout << "YES" << endl;
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
//1R1L1L1