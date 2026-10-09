#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t;
int a, b, c, d;
string s;
vector<int> len[2][2];

void solve() {
	cin >> s >> a >> b >> c >> d;
	// if (t == 10000 - 43) {
	// 	cout << s << endl;
	// 	cout << a << " " << b << " " << c << " " << d << endl;
	// }
	int prev = 0;

	for (int i = 0; i < s.size(); i++) {
		if (i == s.size() - 1 || s[i] == s[i + 1]) {
			len[s[prev] - 'A'][s[i] - 'A'].push_back(i - prev + 1);
			prev = i + 1;
		}
	}

	// for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) {
	// 	for (int k : len[i][j]) cout << k << " ";
	// 	cout << endl;
	// }
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) sort(len[i][j].begin(), len[i][j].end());
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) reverse(len[i][j].begin(), len[i][j].end());

	while (c > 0 && !len[0][1].empty()) {
		int v = len[0][1].back();
		len[0][1].pop_back();
		c--;
		len[0][1].push_back(v - 2);
		while (!len[0][1].empty() && len[0][1].back() == 0) len[0][1].pop_back();
	}

	while (d > 0 && !len[1][0].empty()) {
		int v = len[1][0].back();
		len[1][0].pop_back();
		d--;
		len[1][0].push_back(v - 2);
		while (!len[1][0].empty() && len[1][0].back() == 0) len[1][0].pop_back();
	}

	while (!len[0][1].empty() && len[0][1].back() == 2) {
		len[0][1].pop_back();
		a--; b--;
	}
	while (d > 0 && !len[0][1].empty()) {
		int v = len[0][1].back();
		len[0][1].pop_back();
		d--;
		len[0][1].push_back(v - 2);
		while (!len[0][1].empty() && len[0][1].back() == 2) {
			len[0][1].pop_back();
			a--; b--;
		}
	}

	while (!len[1][0].empty() && len[1][0].back() == 2) {
		len[1][0].pop_back();
		a--; b--;
	}
	while (c > 0 && !len[1][0].empty()) {
		int v = len[1][0].back();
		len[1][0].pop_back();
		c--;
		len[1][0].push_back(v - 2);
		while (!len[1][0].empty() && len[1][0].back() == 2) {
			len[1][0].pop_back();
			a--; b--;
		}
	}

	vector<int> other;
	a -= len[0][0].size();
	b -= len[1][1].size();
	for (int i : len[0][0]) other.push_back(i);
	for (int i : len[1][1]) other.push_back(i);
	sort(other.begin(), other.end());
	reverse(other.begin(), other.end());
	
	while (!other.empty() && other.back() == 1) other.pop_back();
	while (c > 0 && !other.empty()) {
		int v = other.back();
		other.pop_back();
		c--;
		other.push_back(v - 2);
		while (!other.empty() && other.back() == 1) other.pop_back();
	}

	while (!other.empty() && other.back() == 1) other.pop_back();
	while (d > 0 && !other.empty()) {
		int v = other.back();
		other.pop_back();
		d--;
		other.push_back(v - 2);
		while (!other.empty() && other.back() == 1) other.pop_back();
	}
	for (int i : other) {
		a -= i / 2;
		b -= i / 2;
	}
	for (int i : len[0][1]) {
		a -= i / 2;
		b -= i / 2;
	}
	for (int i : len[1][0]) {
		a -= i / 2;
		b -= i / 2;
	}
	if (a >= 0 && b >= 0 && c >= 0 && d >= 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) len[i][j].clear();
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

// ABAB BA AB BA AB
// AB BABA AB
// BABABA ABABAB BA A AB BA BA BA

// BABABAABABABBAAABBABABA
// 3 2 7 2