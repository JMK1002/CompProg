#include <bits/stdc++.h>
using namespace std;

int n, k;
string s, t;
vector<int> inds[30];
int run[30];
vector<int> b;

bool tst(int v) {
	if (v == -1) return false;
	for (int i = 0; i < 30; i++) {
		run[i] = 0;
	}
	b.clear();
	for (int i = 0; i < n; i++) {
		int c = t[i] - 'a';
		while (run[c] < inds[c].size() && inds[c][run[c]] < (b.empty() ? -1 : b.back())) {
			run[c]++;
		}
		while (run[c] < inds[c].size() && inds[c][run[c]] < i - v) run[c]++;
		if (run[c] == inds[c].size() || inds[c][run[c]] > i) return false;
		b.push_back(inds[c][run[c]]);
	}
	return true;
}

void solve() {
	cin >> n >> k >> s >> t;
	for (int i = 0; i < n; i++) {
		inds[s[i] - 'a'].push_back(i);
	}
	if (!tst(k)) {
		cout << -1 << endl;
		return;
	}
	int low = -1;
	int high = k;
	while (high - low > 1) {
		int mid = (high + low) / 2;
		if (tst(mid)) high = mid;
		else low = mid;
	}
	tst(high);
	cout << high << endl;
	for (int i = 0; i < high; i++) {
		for (int j = n - 1; j >= 0; j--) {
			if (b[j] == j) continue;
			s[b[j] + 1] = s[b[j]];
			b[j]++;
		}
		cout << s << endl;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i < 30; i++) inds[i].clear();
	}
	return 0;
}