#include <iostream>
using namespace std;

int dp[200005];

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int p;
	cin >> p;
	for (int i = 1; i <= p; i++) dp[i] = 1e9;
	for (int i = 0; i <= p; i++) {
		for (int j = 2; i + j * (j - 1) / 2 <= p; j++) {
			int x = i + j * (j - 1) / 2;
			dp[x] = min(dp[x], dp[i] + j);
		}
	}
	cout << dp[p] << " " << dp[p] * (dp[p] - 1) / 2 - p << endl;
	return 0;
}