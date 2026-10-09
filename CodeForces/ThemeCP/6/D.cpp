#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> inds[2];
bool explored[100005];

void solve() {
	int x, y;
	cin >> x >> y;
	int s = x + y;
	s %= 2;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		inds[(x + y) % 2].push_back(i + 1);
	}

	if (s) {
		if (inds[0].size() > inds[1].size()) {
			cout << "First" << endl;
		}
		else {
			cout << "Second" << endl;

		}
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