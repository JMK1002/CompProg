#include <iostream>
#include <vector>
using namespace std;

int n, t;
int arr[5005];
int dp[5005];
int run[5005];

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// if (t == 1000 - 103) {
	// 	for (int i = 1; i <= n; i++) cout << arr[i] << " "
	// }

	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j <= n; j++) run[j] = 0;
		int cnt = 0;
		dp[i] = -1e9;
		for (int j = i - 1; j >= 0; j--) {
			if ((i == n + 1 || j == 0 || arr[j] == arr[i]) && cnt <= (i - 1 - j) / 2 && (i - 1 - j) % 2 == 0) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
			run[arr[j]]++;
			cnt = max(cnt, run[arr[j]]);
		}
	}
	
	cout << dp[n + 1] - 1 << endl;

	for (int i = 0; i <= n + 1; i++) {
		arr[i] = 0;
		dp[i] = 0;
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);

	cin >> t;
	while (t--) {
		solve();
	}
}