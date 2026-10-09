#include <bits/stdc++.h>
using namespace std;

int n;
string s;
int arr[200005];

void solve() {
	cin >> n >> s;
	s = "1" + s + "1";
	int earliest = -1;
	for (int i = 1; i <= n; i++) arr[i] = i;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == '1' && s[i] == '0' && s[i + 1] == '1') {
			cout << "NO" << endl;
			return;
		}
		if (s[i] == '0' && s[i - 1] == '1') earliest = i;
		if (s[i] == '0' && s[i + 1] == '1') swap(arr[i], arr[earliest]);
	}
	cout << "YES" << endl;
	for (int i = 1; i <= n; i++) cout << arr[i] << " ";
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
}