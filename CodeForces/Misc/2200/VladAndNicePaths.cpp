#include <iostream>
#include <vector>
using namespace std;

const long long mod = 1e9+7;

long long n, k;
pair<long long, long long> dp[5005];
vector<long long> inds[5005];
long long fact[5005];
long long invFact[5005];

long long binpow(long long a, long long b) {
	long long res = 1;
	long long run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		res %= mod;
		run %= mod;

		b >>= 1;
	}
	return res;
}

long long ch(long long a, long long b) {
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

void solve() {
	cin >> n >> k;
	dp[0] = {0, 1};
	for (long long i = 1; i <= n; i++) {
		long long c;
		cin >> c;
		inds[c].push_back(i);
		dp[i] = dp[i - 1];
		for (long long j = 0; j < (long long) inds[c].size() - k + 1; j++) {
			long long ind = inds[c][j];
			if (dp[i].first == dp[ind - 1].first + 1) dp[i].second += dp[ind - 1].second * ch(inds[c].size() - j - 2, k - 2) % mod;
			else if (dp[i].first < dp[ind - 1].first + 1) dp[i] = {dp[ind - 1].first + 1, dp[ind - 1].second * ch(inds[c].size() - j - 1, k - 1) % mod};
			dp[i].second %= mod;
		}
	}
	cout << dp[n].second << endl;

	for (long long i = 0; i <= n; i++) {
		dp[i] = {0, 0};
		inds[i].clear();
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;

	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i < 5005; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = binpow(fact[i], mod - 2);
	}

	while (t--) {
		solve();
	}
	return 0;
}