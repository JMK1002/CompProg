#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

long long n;
long long arr[200005];
long long fact[200005];
long long invFact[200005];
long long f[200005];
vector<long long> cnt[200005];
vector<long long> preCnt[200005];

long long ch(long long a, long long b) {
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

long long binpow(long long a, long long b) {
	long long res = 1;
	long long run = a;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;
		run *= run;
		run %= mod;
		b >>= 1;
	}
	return res;
}

void solve() {
	cin >> n;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		f[arr[i]]++;
	}
	long long preMin = f[0];
	cnt[0] = vector<long long>(preMin + 2);
	preCnt[0] = vector<long long>(preMin + 2);
	for (long long i = f[0]; i >= 0; i--) {
		cnt[0][i] = ch(f[0], i);
		preCnt[0][i] = preCnt[0][i + 1] + cnt[0][i];
		preCnt[0][i] %= mod;
	}

	for (long long i = 1; i < n; i++) {
		preMin = min(preMin, f[i]);
		cnt[i] = vector<long long>(preMin + 2);
		preCnt[i] = vector<long long>(preMin + 2);

		long long chSum = binpow(2, f[i]) - 1;
		for (long long j = 0; j <= preMin; j++) {
			cnt[i][j] = preCnt[i - 1][j] * ch(f[i], j) % mod;
			cnt[i][j] += chSum * cnt[i - 1][j] % mod;
			cnt[i][j] %= mod;

			chSum -= ch(f[i], j + 1) - mod;
			chSum %= mod;
		}

		for (int j = preMin; j >= 0; j--) {
			preCnt[i][j] = preCnt[i][j + 1] + cnt[i][j];
			preCnt[i][j] %= mod;
		}
	}

	long long ans = 0;
	long long tot = n;
	for (long long i = 0; i < n; i++) {
		tot -= f[i];
		for (long long j = 0; j < cnt[i].size(); j++) {
			ans += cnt[i][j] * j % mod * binpow(2, tot) % mod;
			ans %= mod;
		}
	}
	cout << ans << endl;

	for (long long i = 0; i <= n; i++) {
		arr[i] = 0;
		f[i] = 0;
		cnt[i].clear();
		preCnt[i].clear();
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);

	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i <= 200000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = binpow(fact[i], mod - 2);
	}

	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}