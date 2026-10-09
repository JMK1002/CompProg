#include <iostream>
using namespace std;

int n, m;
string s;

void solve() {
	cin >> n >> m >> s;
	int cnt = 0;
	for (char c : s) cnt += c == '1';
	if (cnt <= m || m * 2 > n) {
		cout << "Alice" << endl;
	}
	else cout << "Bob" << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}