#include <bits/stdc++.h>
using namespace std;

int n;

bool isAlt(string s) {
	bool ans = true;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) ans = false;
	}
	return ans;
}

void flip(string & s, int l, int r) { // ! O(n)
	for (int i = l; i <= r; i++) {
		if (s[i] == '0') s[i] = '1';
		else s[i] = '0';
	}
}

vector<pair<int, int>> getSeq(string s) {
	vector<pair<int, int>> ans;
	if (isAlt(s)) {
		ans.push_back({0, 2});
		flip(s, 0, 2);
	}
	int l, r;
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			l = i;
			r = i + 1;
		}
	}

	while (l > 0 && s[l - 1] == s[l]) l--;
	while (r < n - 1 && s[r + 1] == s[r]) r++;

	while (!(l == 0 && r == n - 1 && s[0] == '0')) {
		ans.push_back({l, r});
		flip(s, l, r);
		while (l > 0 && s[l - 1] == s[l]) l--;
		while (r < n - 1 && s[r + 1] == s[r]) r++;
	}
	return ans;
}

void solve() {
	string s, t;
	cin >> n >> s >> t;
	vector<pair<int, int>> a = getSeq(s);
	vector<pair<int, int>> b = getSeq(t);
	reverse(b.begin(), b.end());

	cout << a.size() + b.size() << endl;
	for (pair<int, int> p : a) cout << p.first + 1 << " " << p.second + 1 << endl;
	for (pair<int, int> p : b) cout << p.first + 1 << " " << p.second + 1 << endl;

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