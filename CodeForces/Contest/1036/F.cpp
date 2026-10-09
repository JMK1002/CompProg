#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>
using namespace std;

const long long MAXN = 105;
const long long mod = 998244353;

long long n, m;
bool valid[MAXN][MAXN][MAXN];
long long dp[MAXN]; // ! DONT FORGET TO MAKE IT LONG LONG AAAAAAAAAH
long long help[MAXN][MAXN];
set<long long> restrictions[MAXN];

void solve() {
	cin >> n >> m;
	for (long long i = 0; i < m; i++) {
		long long a, b;
		cin >> a >> b;
		restrictions[a].insert(b);
	}
	for (long long i = 0; i <= n; i++) for (long long j = 0; j <= n; j++) valid[i][j][0] = true;
	for (long long i = 1; i <= n; i++) {
		for (long long j = 1; j <= n; j++) {
			valid[i][j][0] = true;
			for (long long len = 1; len <= i; len++) {
				valid[i][j][len] = valid[i][j][len - 1];
				valid[i][j][len] &= restrictions[i - len + 1].find(j - len + 1) == restrictions[i - len + 1].end();
			}
		}
	}
	dp[0] = 1;
	for (long long i = 1; i <= n; i++) {
		for (long long len = 1; len <= i; len++) {
			for (long long shift = 0; shift < len; shift++) {
				int end = len - shift;
				bool works = valid[i][end][end] && valid[i - end][len][shift];

				bool subtract = true;
				if (len == 1) subtract = false;
				else if (shift == 0) subtract = false;

				dp[i] += works * (dp[i - len] - subtract * help[i - len][end]);
				help[i][end] += works * (dp[i - len] - subtract * help[i - len][end]);
				dp[i] %= mod;
			}
		}
	}
	cout << dp[n] << endl;
	for (int i = 0; i <= n; i++) {
		dp[i] = 0;
		restrictions[i].clear();
		for (int j = 0; j <= n; j++) {
			help[i][j] = 0;
			for (int k = 0; k <= n; k++) {
				valid[i][j][k] = false;
			}
		}
	}
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