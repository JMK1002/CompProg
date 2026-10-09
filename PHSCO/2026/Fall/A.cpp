#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long amnt[2][3];
	for (long long i = 0; i < 2; i++) for (long long j = 0; j < 3; j++) cin >> amnt[i][j];
	long long s[2] = {0, 0};
	for (long long i = 0; i < 2; i++) for (long long j = 0; j < 3; j++) s[i] += amnt[i][j];
	long long ans = 0;

	for (long long i = 0; i <= 100; i++) {
		long long need = 0;
		long long give = 0;
		for (long long j = 0; j < 3; j++) {
			if (amnt[0][j] + amnt[1][j] < i) {
				need = 1e9;
				give = 0;
				break;
			} 
			need += max(0ll, i - amnt[0][j]);
			give += max(0ll, amnt[0][j] - i);
		}
		if (need <= give) ans = i;
	}
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