#include <iostream>
#include <algorithm>
using namespace std;

int n, q;
int arr[100005];
int ans[100005];
int cnt[100005];
int pre[100005];

bool bin(int i, int target) {
	int ret = 0;
	for (int j = 0; j <= n; j += i) {
		ret += pre[min(n, j + target)] - (j - 1 < 0 ? 0 : pre[j - 1]);
	}
	return ret > n/2;
}

void solve() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	pre[0] = cnt[0];
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + cnt[i];
	for (int i = 1; i <= n; i++) {
		int low = 0;
		int high = i - 1;
		if (bin(i, low)) {
			ans[i] = low;
			continue;
		}
		while (high - low > 1) {
			int mid = (high + low) / 2;
			if (bin(i, mid)) high = mid;
			else low = mid;
		}
		ans[i] = high;
	}
	while (q--) {
		int x;
		cin >> x;
		cout << ans[x] << " ";
	}
	cout << endl;
	for (int i = 0; i <= n; i++) {
		pre[i] = 0;
		cnt[i] = 0;
		arr[i] = 0;
		ans[i] = 0;
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