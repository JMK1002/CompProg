#include <iostream>
#include <algorithm>
using namespace std;

int n;
string s;
bool par[100005];
bool currPar[100005];
pair<int, int> ans[100005];

void op(int a, int b) {
	if (a > b) swap(a, b);
	currPar[a] ^= 1;
	currPar[b] ^= 1;
	swap(ans[a].second, ans[b].first);
}

void solve() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) par[i] = s[i] == 'O';
	for (int i = 0; i < n; i++) currPar[i] = 1;
	for (int i = 0; i < n; i++) ans[i] = {2 * i + 1, 2 * i + 2};
	for (int i = 0; i < n - 1; i++) {
		if (currPar[i] != par[i]) op(i, i + 1);
	}
	if (currPar[n - 1] != par[n - 1]) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) cout << ans[i].first << " " << ans[i].second << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}