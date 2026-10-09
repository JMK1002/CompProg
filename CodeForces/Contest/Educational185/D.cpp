#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;

void solve() {
	cin >> n >> q >> s;
	s += "_";
	string t = s;

	int bad = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'X') bad += 10;
		if (s[i] == 'V') bad += 5;
		if (s[i] == 'I') {
			bad++;
			if ((s[i + 1] == 'V' || s[i + 1] == 'X')) bad -= 2;
		}
	}

	int alt = 0;
	int cntI = 0;
	int cntV = 0;
	int both = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) if (t[i] == 'X') t[i] = 'V';
	for (int i = 0; i < n; i++) cnt += t[i] == '?';
	int l = -1;
	for (int i = 0; i <= n; i++) {
		if (l != -1 && t[i] != '?') {
			int r = i - 1;
			if (t[i] == 'V') {
				r--; cntV++;
			}
			if (l != 0 && t[l - 1] == 'I') {
				l++; cntI++;
			}
			if (l > r + 1) {
				cntV--; cntI--; both++;
			}
			alt += (r - l + 1) / 2;
			l = -1;
		}
		else if (t[i] == '?') {
			if (i == 0 || t[i - 1] != '?') l = i;
		}
	}

	while (q--) {
		int x, v, i;
		cin >> x >> v >> i;
		if (i >= cnt) {
			v = 0;
			x = 0;
			i = cnt;
		}
		else if (i + v >= cnt) {
			x = 0;
			v = cnt - i;
		}
		else {
			x = cnt - i - v;
		}
		int a = min(cntV, i);
		int b = min(cntI, v + x);
		int c;
		if (max(i - a, v + x - b) - both < min(i - a, v + x - b)) c = (i - a + v + x - b - both) / 2;
		else c = max(min(i - a - both, v + x - b), min(i - a, v + x - b - both));
		cout << bad + x * 10 + v * 5 + i - 2 * (both + a + b + min(alt, c)) << endl;
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
// ???I?V