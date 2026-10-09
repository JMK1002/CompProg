#include <iostream>
using namespace std;

int n, q;
int arr[300005];
int ans[300005];
int temp[300005];
pair<int, pair<int, int>> queries[300005];

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) ans[i] = arr[i];
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		x--; y--; z--;
		queries[i] = {x, {y, z}};
	}
	for (int i = q - 1; i >= 0; i--) {
		int x = queries[i].first;
		int y = queries[i].second.first;
		int z = queries[i].second.second;
		int zVal = ans[z];
		ans[x] = max(ans[x], ans[z]);
		ans[y] = max(ans[y], ans[z]);
		if (z != x && z != y) ans[z] = 0;
	}
	for (int i = 0; i < n; i++) temp[i] = ans[i];
	for (int i = 0; i < q; i++) {
		int x = queries[i].first;
		int y = queries[i].second.first;
		int z = queries[i].second.second;
		temp[z] = min(temp[x], temp[y]);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != temp[i]) {
			cout << -1 << endl;
			return;
		}
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	cout << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
		for (int i = 0; i <= n; i++) {
			arr[i] = 0;
			ans[i] = 0;
			temp[i] = 0;
		}
		for (int i = 0; i <= q; i++) queries[i] = {0, {0, 0}};
	}
	return 0;
}