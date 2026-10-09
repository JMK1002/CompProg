#include <bits/stdc++.h>
using namespace std;

int n, k;
int dp[1000];
int amnt[1000];

void solve() {
	cin >> n >> k;
	int tar = n * n - 2 * k - n;
	for (int i = 1; i <= tar; i++) dp[i] = 1e9;
	for (int i = 1; i <= tar; i++) {
		for (int j = 1; i - j * (j - 1) >= 0; j++) {
			if (dp[i - j * (j - 1)] + j <= dp[i]) {
				dp[i] = dp[i - j * (j - 1)] + j;
				amnt[i] = j;
			}
		}
	}
	if (dp[tar] <= n) {
		int ptr = tar;
		vector<int> amnts;
		int s = 0;
		while (ptr) {
			int x = amnt[ptr];
			ptr -= x * (x - 1);
			amnts.push_back(x);
			s += x;
		}
		while (s < n) {
			amnts.push_back(1);
			s++;
		}

		int cnt = n;
		for (int i : amnts) {
			for (int j = cnt - i + 1; j <= cnt; j++) {
				cout << j << " ";
			}
			cnt -= i;
		}
		cout << endl;
	}
	else cout << 0 << endl;
	for (int i = 0; i <= tar; i++) {
		dp[i] = 0;
		amnt[i] = 0;
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