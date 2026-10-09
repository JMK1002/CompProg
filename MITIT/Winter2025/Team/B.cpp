#include <bits/stdc++.h>
using namespace std;

string getAns(int m, int i, int t) {
	if (m < 0 || i < 0 || t < 0) return "-1";
	int a = m + i - t;
	int c = m - i + t;
	int b = i + t - m;
	if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1 || a < 0 || b < 0 || c < 0) return "-1";
	string ans;
	for (int j = 0; j < a / 2; j++) ans += "IM";
	for (int j = 0; j < c / 2; j++) ans += "TM";
	for (int j = 0; j < b / 2; j++) ans += "TI";
	return ans;
}

void solve() {
	int m, i, t;
	cin >> m >> i >> t;
	string ans;
	if (getAns(m, i, t) != "-1") ans = getAns(m, i, t);
	else if (getAns(m - 1, i, t) != "-1") ans = "M" + getAns(m - 1, i, t);
	else if (getAns(m, i, t - 1) != "-1") ans = getAns(m, i, t - 1) + "T";
	else if (getAns(m - 1, i, t - 1) != "-1") ans = "M" + getAns(m - 1, i, t - 1) + "T";
	
	if (t == 0 && i == m + 1) ans = getAns(m, i - 1, t) + "I";
	else if (m == 0 && i == t + 1) ans = "I" + getAns(m, i - 1, t);

	if (ans == "") {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << ans << endl;
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