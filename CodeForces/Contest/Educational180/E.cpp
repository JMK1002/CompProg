#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int MAXN = 500005;
int dp[MAXN];

// void solve() {

// }

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);

	for (int i = 0; i < MAXN; i++) dp[i] = -1;
	dp[1] = 1;
	for (int i = 3; i < MAXN; i += 2) {
		dp[i] = dp[i - 2] + 1;
		for (int j = 1; j * j <= i; j += 2) {
			if (i % j != 0) continue;
			dp[i] = min(dp[i], dp[j] + dp[i / j] - 1);
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> m;
		cout << dp[m] << endl;
	}
}