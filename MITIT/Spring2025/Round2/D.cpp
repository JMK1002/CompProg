#include <iostream>
using namespace std;

long long n, k;
long long arr[5000];
long long lg[5000][5000];
long long inv[5000][5000];

void solve() {
	cin >> n >> k;
	for (long long i = 0; i < n; i++) cin >> arr[i];
	long long s = 0;
	for (long long i = 0; i < n; i++) {
		for (long long j = i - 1; j >= 0; j--) {
			lg[j][i] = lg[j + 1][i] + (arr[j] > arr[i]);
		}
	}
	for (long long i = 0; i < n; i++) {
		for (long long j = i + 1; j < n; j++) {
			inv[i][j] = inv[i][j - 1] + lg[i][j];
		}
	}
	long long ans = 0;
	for (long long i = 0; i < n; i++) for (long long j = i + 1; j < n; j++) {
		if (inv[i][j] % k != 0) ans = max(ans, j - i + 1);
	}
	if (ans == 0) cout << -1 << endl;
	else cout << ans << endl;
	for (long long i = 0; i <= n; i++) {
		arr[i] = 0;
		for (long long j = 0; j <= n; j++) {
			lg[i][j] = 0;
			inv[i][j] = 0;
		}
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) solve();
	return 0;
}