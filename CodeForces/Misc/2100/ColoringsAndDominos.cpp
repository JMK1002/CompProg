#include <iostream>
#include <vector>
using namespace std;

const int mod = 998244353;

vector<bool> arr[300005];
vector<bool> flipped[300005];
long long dp[300005];
int cnt[300005];

long long binpow(int a, int b) {
	if (b < 0) return 0;
	long long run = a;
	long long res = 1;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		res %= mod;
		run %= mod;
		b >>= 1;
	}
	return res;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		// for (int j = 0; j < m; j++) {
		// 	s += (rand() % 6) ? 'o' : '*';
		// }
		int run = 0;
		for (int j = 0; j < m; j++) {
			tot += s[j] == 'o';
			arr[i].push_back(s[j] == 'o');
			if (s[j] == 'o') run++;
			else {
				cnt[run]++;
				run = 0;
			}
		}
		if (run != 0) {
			cnt[run]++;
			run = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			flipped[i].push_back(arr[j][i]);
		}
	}
	for (int i = 0; i < m; i++) {
		int run = 0;
		for (int j = 0; j < n; j++) {
			if (flipped[i][j]) run++;
			else {
				cnt[run]++;
				run = 0;
			}
		}
		if (run != 0) {
			cnt[run]++;
			run = 0;
		}
	}
	dp[2] = 1;
	for (long long i = 3, run = 1; i <= max(m, n); i++) {
		dp[i] = dp[i - 1] * 2 + run;
		run *= 2;
		run += (i % 2 == 1 ? 1 : -1);
		run %= mod;
		dp[i] %= mod;
	}

	long long ans = 0;
	for (int i = 2; i <= max(n, m); i++) {
		ans += dp[i] * cnt[i] % mod * binpow(2, tot - i) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}