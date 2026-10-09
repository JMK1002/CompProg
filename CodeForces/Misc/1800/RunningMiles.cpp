#include <iostream>
using namespace std;

int n;
int arr[100005];
int pre[100005];
int suff[100005];

void solve() {
	cin >> n;
	suff[n + 1] = -1e9;
	pre[0] = -1e9;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], arr[i] + i);
	for (int i = n; i >= 1; i--) suff[i] = max(suff[i + 1], arr[i] - i);
	int ans = 0;
	for (int i = 2; i < n; i++) ans = max(ans, arr[i] + pre[i - 1] + suff[i + 1]);
	cout << ans << endl;
	for (int i = 0; i <= n + 1; i++) {
		arr[i] = 0;
		pre[i] = 0;
		suff[i] = 0;
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