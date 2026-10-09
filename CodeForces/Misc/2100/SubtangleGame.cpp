#include <iostream>
using namespace std;

int l, n, m;
int arr[303];
int mat[303][303];
bool dp[303][303][303];

void solve() {
	cin >> l >> n >> m;
	for (int i = 0; i < l; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> mat[i][j];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			for (int k = 0; k < l; k++) {
				if (mat[i][j] == arr[k]) dp[i][j][k] = !dp[i + 1][j + 1][k + 1];
				dp[i][j][k] |= dp[i + 1][j][k];
				dp[i][j][k] |= dp[i][j + 1][k];
			}
		}
	}
	cout << (dp[0][0][0] ? 'T' : 'N') << endl;

	for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) for (int k = 0; k <= l; k++) dp[i][j][k] = 0;
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