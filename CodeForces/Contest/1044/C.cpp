#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> len[1000];

bool hasEdge(int u, int v) {
	cout << "? " << u << " 2 " << u << " " << v << endl;
	cout.flush();
	int x;
	cin >> x;
	if (x == 2) return true;
	else return false;
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) len[i].second = i;
	for (int i = 1; i <= n; i++) {
		cout << "? " << i << " " << n << " ";
		for (int j = 1; j <= n; j++) cout << j << " ";
		cout << endl;
		cout.flush();
		cin >> len[i].first;
	}
	sort(len + 1, len + n + 1);
	vector<int> ans;
	int pos = n;
	while (len[pos].first > 1) {
		for (int i = pos - 1; i >= 1; i--) {
			if (len[i].first != len[pos].first - 1) continue;
			if (hasEdge(len[pos].second, len[i].second)) {
				ans.push_back(len[pos].second);
				pos = i;
				break;
			}
		}
	}
	ans.push_back(len[pos].second);
	cout << "! " << ans.size() << " ";
	for (int i : ans) cout << i << " ";
	cout << endl;
	cout.flush();

	for (int i = 0; i <= n; i++) len[i] = {0, 0};
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}