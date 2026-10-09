#include <bits/stdc++.h>
using namespace std;

int n, m, k;
string s;
bool in[3005];
int dp[3005][3005]; // [i][j] is prefix of i, j moves done

void solve() {
	cin >> n >> m >> k >> s;
	for (int i = 1; i < n; i++) in[i] = (s[i] == s[i - 1]);
	for (int i = 0; i < n; i++) {
		for (int j = i - k, cnt = 1; j >= 0; j -= k, cnt++) {
			if (j == 0) 
		}
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