#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int n;
int arr[100005];
int pre[11][100005];
int last[11];
map<int, vector<int>> asdf[11];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		arr[i] = x;
		for (int j = 1; j <= 10; j++) {
			pre[j][i] = pre[j][i - 1] + ((x <= j) ? 1 : -1);
		}
	}
	for (int i = 1; i <= 10; i++) last[i] = -1;

	long long ans = (long long) n * (n + 1) / 2;
	for (int i = 0; i <= n; i++) {
		last[arr[i]] = i;
		for (int j = 1;  j <= 10; j++) {
			int cnt = lower_bound(asdf[j][pre[j][i]].begin(), asdf[j][pre[j][i]].end(), last[j]) - asdf[j][pre[j][i]].begin();
			ans -= cnt;
			asdf[j][pre[j][i]].push_back(i);
		}
	}
	cout << ans << endl;

	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		for (int j = 0; j <= 10; j++) {
			pre[j][i] = 0;
		}
	}
	for (int i = 0; i <= 10; i++) {
		last[i] = 0;
		asdf[i].clear();
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