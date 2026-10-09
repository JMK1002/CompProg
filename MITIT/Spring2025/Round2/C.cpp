#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s;
const char chars[] = {'r', 'g', 'b', 'y'}; 

// check if can reach a valid other character or if stuck
// if cannot returns the char it cannot
char reachValid(int ind) {
	set<char> st;
	for (int i = max(0, ind - 2); i <= min(n - 1, ind + 2); i++) {
		st.insert(s[i]);
	}
	if (st.size() == 4) return '0';
	for (char c : chars) {
		if (st.find(c) == st.end()) return c;
	}
	return '0';
}

int getLatest(int ind) {
	vector<char> v;
	for (int i = max(0, ind - 2); i <= min(n - 1, ind + 2); i++) {
		v.push_back(s[i]);
	}
	sort(v.begin(), v.end());
	char rep = '0';
	for (int i = 0; i < 4; i++) if (v[i] == v[i + 1]) rep = v[i];
	if (rep == '0' || (ind != 1 && rep == s[ind - 2])) return ind - 1;
	return ind - 2;
}

char missing() {
	set<char> st;
	for (int i = 0; i < n; i++) {
		st.insert(s[i]);
	}
	if (st.size() == 4) return '0';
	for (char c : chars) {
		if (st.find(c) == st.end()) return c;
	}
	return '0';
}

void solve() {
	cin >> n >> s;
	if (missing() != '0') {
		char c = missing();
		for (int i = 0; i < n; i++) cout << c;
		cout << endl;
		return;
	}

	int on = n;
	string ns = "";
	ns += s[0];
	for (int i = 1; i < n; i++) {
		if (s[0] == s[i] && ns.size() == 1) continue;
		ns += s[i];
	}
	s = ns;
	n = s.size();
	string ans = "";
	ans += s[n - 1];
	int pos = n - 1;
	while (pos) {
		char c = reachValid(pos);
		if (c != '0') { // ! might cry if size of s = 2 or 3 or char doesnt exist
			ans += c;
			while (pos > 0 && s[pos] != c) pos--;
			continue;
		}
		pos = getLatest(pos);
		ans += s[pos];
	}
	ans += reachValid(0);
	while (ans.size() < on) ans += 'y';
	cout << ans << endl;
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
// 12
// rgbyrgbyrgby