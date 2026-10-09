#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[5005];
long long dp[5005];
long long mn[5005];
long long temp[5005];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	reverse(arr + 1, arr + (n + 1));
	for (int i = 0; i <= n; i++) {
		dp[i] = 1e18;
		mn[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp[j] = dp[j] + 1 + arr[j];
			if (j >= i) {
				temp[j] = min(temp[j], mn[j - 1] + (j - i) + arr[j]);
			}
		}
		for (int j = 1; j <= n; j++) dp[j] = temp[j];

		mn[0] = 1e18;
		for (int j = 1; j <= n; j++) {
			mn[j] = min(mn[j - 1], dp[j]);
		}
	}
	cout << mn[n] << endl;
	for (int i = 0; i <= n; i++) {
		arr[i] = 0;
		dp[i] = 0;
		mn[i] = 0;
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