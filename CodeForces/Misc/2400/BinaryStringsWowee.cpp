#include <iostream>
using namespace std;

const long long mod = 998244353;

long long n, k;
string s;
bool arr[1000];
long long dp[502][502];
long long fact[1000];
long long invFact[1000];

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long ch(long long a, long long b) {
	if (b > a) return 0;
	return fact[a] * invFact[b] % mod * invFact[a - b]z % mod;
}

void solve() {
	cin >> n >> k >> s;
	for (long long i = 0; i < n; i++) arr[i] = s[i] == '1';

	for (long long i = n - 1; i >= 0; i--) {
		dp[i][1] = !arr[i] + dp[i + 1][1];
	}

	for (long long i = n - 1; i >= 0; i--) {
		for (long long j = 2; j <= k; j++) {
			long long totSlots = (arr[i] == 0) * (j % 2) + j / 2;
			for (long long l = 0; l <= totSlots; l++) {
				dp[i][j] += ch(totSlots, l) * dp[i + 1][j - l] % mod;
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[0][k] << endl;
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) dp[i][j] = 0;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	fact[0] = 1;
	invFact[0] = 1;
	for (long long i = 1; i < 1000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = inv(fact[i]);
	}
	while (t--) {
		solve();
	}
	return 0;
}
