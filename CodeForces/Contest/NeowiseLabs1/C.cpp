#include <iostream>
using namespace std;

const long long INF = 2e17;

long long n;
long long arr[1004][1004];
long long narr[1004][1004];
long long r[1004][2];
long long dp[1004][2]; // i, activated;

void doThing(bool b) {
	dp[0][1] = r[0][b];
	for (long long i = 1; i < n; i++) {
		bool exists[3] = {false, false, false}; // -1, 0, 1
		for (long long j = 0; j < n; j++) {
			long long diff = arr[i][j] - arr[i - 1][j];
			if (diff == -1) exists[0] = true;
			if (diff == 0) exists[1] = true;
			if (diff == 1) exists[2] = true;
		}
		dp[i][0] = INF;
		dp[i][1] = INF;
		if (!exists[1]) {
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + r[i][b]);
		}
		if (!exists[0]) {
			dp[i][1] = min(dp[i][1], dp[i - 1][0] +  + r[i][b]);
		}
		if (!exists[2]) {
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
	}
}

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) cin >> arr[i][j];
	for (long long i = 0; i < n; i++) cin >> r[i][0];
	for (long long i = 0; i < n; i++) cin >> r[i][1];
	doThing(false);
	long long ans = min(dp[n - 1][0], dp[n - 1][1]);
	if (dp[n - 1][0] == INF && dp[n - 1][1] == INF) {
		cout << -1 << endl;
		return;
	}

	for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) narr[i][j] = arr[j][i];
	for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) arr[i][j] = narr[i][j];
	doThing(true);
	if (dp[n - 1][0] == INF && dp[n - 1][1] == INF) {
		cout << -1 << endl;
		return;
	}
	ans += min(dp[n - 1][0], dp[n - 1][1]);
	cout << ans << endl;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}