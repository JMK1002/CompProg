#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, t;
int n, m;
int nxt[100005][30];
int prv[100005][30];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> s >> t;
	n = s.size();
	m = t.size();

	for (int i = 0; i < 30; i++) {
		prv[0][i] = -1;
		nxt[n - 1][i] = -1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 30; j++) prv[i][j] = prv[i - 1][j];
		prv[i][s[i - 1] - 'a'] = i - 1;
	}
	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < 30; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][s[i + 1] - 'a'] = i + 1;
	}

	int l = 0;
	int cl = -1;
	int r = 0;
	int cr = n;
	
	vector<int> cls;
	cls.push_back(cl);

	if (cl == -1) {
		if (t[0] == s[0]) {
			cl = 0;
			cls.push_back(cl);
			l++;
		}
		else if (nxt[0][t[0] - 'a'] != -1) {
			cl = nxt[0][t[0] - 'a'];
			cls.push_back(cl);
			l++;
		}
	}

	while (l < m && cl != -1 && nxt[cl][t[l] - 'a'] != -1) {
		cl = nxt[cl][t[l] - 'a'];
		cls.push_back(cl);
		l++;
	}

	if (cr == n) {
		if (t[m - 1] == s[n - 1] && cl < n - 1) {
			cr = n - 1;
			r++;
		}
		else if (prv[n - 1][t[m - 1] - 'a'] != -1 && cl < prv[n - 1][t[m - 1] - 'a']) {
			cr = prv[n - 1][t[m - 1] - 'a'];
			r++;
		}
	}

	while (r < m && cr != n && prv[cr][t[m - 1 - r] - 'a'] != -1 && cl < prv[cr][t[m - 1 - r] - 'a']) {
		cr = prv[cr][t[m - 1 - r] - 'a'];
		r++;
	}

	pair<int, int> ans = {l, r};
	for (int i = cls.size() - 1; i >= 0; i--) {
		l = i;
		cl = cls[i];

		if (cr == n) {
			if (t[m - 1] == s[n - 1] && cl < n - 1) {
				cr = n - 1;
				r++;
			}
			else if (prv[n - 1][t[m - 1] - 'a'] != -1 && cl < prv[n - 1][t[m - 1] - 'a']) {
				cr = prv[n - 1][t[m - 1] - 'a'];
				r++;
			}
		}

		while (r < m && cr != n && prv[cr][t[m - 1 - r] - 'a'] != -1 && cl < prv[cr][t[m - 1 - r] - 'a']) {
			cr = prv[cr][t[m - 1 - r] - 'a'];
			r++;
		}
		if (ans.first + ans.second < l + r) ans = {l, r};
	}
	// cout << ans.first << " " << ans.second << endl;
	if (ans.first + ans.second >= m) ans = {m, 0};
	string strAns = t.substr(0, ans.first) + t.substr(m - ans.second);
	if (strAns == "") strAns = "-";
	cout << strAns << endl;
	return 0;
}

// abcdeggedcba
// abcacba