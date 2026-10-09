#include <iostream>
#include <vector>
using namespace std;

const int high = 2e7;

int n, i, j, arr;
long long cnt[high + 5];
long long dp[high + 5];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr;
		for (j = 1; j * j <= arr; j++) {
			if (arr % j != 0) continue;
			cnt[j]++;
			cnt[arr / j] += (j * j != arr);
		}
	}
	long long ans = 0;
	for (i = high; i >= 1; i--) {
		if (!cnt[i]) continue;
		dp[i] = i * cnt[i];
		if (cnt[i] == n) ans = max(ans, dp[i]);
		for (j = i * 2; j <= high; j += i) {
			if (!cnt[j]) continue;
			dp[i] = max(dp[i], dp[j] + i * (cnt[i] - cnt[j]));
		}
		if (cnt[i] == n) ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}