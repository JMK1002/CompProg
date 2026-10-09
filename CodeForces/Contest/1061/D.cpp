#include <bits/stdc++.h>
using namespace std;

int n;
set<int> inds;

void solve() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		inds.insert(i);
	}

	int cnt = n / 2;
	int ans = 0;
	int opp = 0;
	int run = 1;
	while (!inds.empty()) {
		vector<bool> v;
		int cnt = 0;
		int g = opp + run; // guess
		int e = (inds.size() + 1 + (ans == 0)) / 2; // expected amnt of ones
		for (int i : inds) {
			cout << "? " << i << " " << g << endl;
			cout.flush();
			int x;
			cin >> x;
			v.push_back(x);
			if (x) cnt++;
		}
		if (cnt != e) ans += run;
		else opp += run;

		int asdf = 0;
		vector<int> rem;
		for (int i : inds) {
			if (v[asdf] == (cnt == e)) rem.push_back(i);
			asdf++;
		}
		for (int i : rem) inds.erase(i);

		run <<= 1;
	}
	if (ans == 0) ans += run;
	cout << "! " << ans << endl;
	cout.flush();
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