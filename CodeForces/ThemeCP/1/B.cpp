#include <bits/stdc++.h>
using namespace std;

int n, m;
string s;
int nxt[200005];
int prv[200005];
set<pair<int, int>> cnt;

void solve() {
	cin >> n >> m >> s;

	stack<int> st;
	for (int i = 0; i < n; i++) {
		nxt[i] = n + 1;
		prv[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		st.push(i);
		if (s[i] == '1') {
			while (!st.empty()) {
				nxt[st.top()] = i;
				st.pop();
			}
		}
	}
	while (!st.empty()) st.pop();
	for (int i = n - 1; i >= 0; i--) {
		st.push(i);
		if (s[i] == '0') {
			while (!st.empty()) {
				prv[st.top()] = i;
				st.pop();
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		u = nxt[u];
		v = prv[v];
		if (u >= v) {
			u = -1;
			v = -1;
		}
		cnt.insert(make_pair(u, v));
	}	
	cout << (cnt.size()) << endl;
	for (int i = 0; i <= n; i++) {
		prv[i] = 0;
		nxt[i] = 0;
	}
	cnt.clear();
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