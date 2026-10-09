#include <iostream>
#include <vector>
using namespace std;

const long long mod = 998244353;

long long n;
long long arr[200005];
long long p[200005];
long long dp[200005];
int calc[102][200005];
int probs[102];

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main() {
	cin >> n;
	long long inv100 = inv(100);
	for (int i = 1; i < 100; i++) probs[i] = i * inv100 % mod;
	for (long long i = 1; i <= n; i++) {
		cin >> arr[i];
		p[i] = arr[i] * inv100;
		p[i] %= mod;
	}
	for (long long i = 1; i <= n; i++) {
		for (int j = 0; j < 100; j++) {
			calc[j][i] = calc[j][i - 1] * probs[j] % mod;
			calc[j][i] -= dp[i - 1] * probs[j] % mod * ((1 - probs[j] + mod) % mod) % mod;
			calc[j][i] %= mod;
			calc[j][i] += mod;
			calc[j][i] %= mod;
		}
		dp[i] = dp[i - 1] + 1;
		// for (long long r = p[i] * ((1 - p[i] + mod) % mod) % mod, j = i - 1; j >= 0; j--, r *= p[i], r %= mod) {
		// 	dp[i] -= dp[j] * r % mod;
		// 	dp[i] %= mod;
		// 	// cout << r << endl;
		// }
		dp[i] += calc[arr[i]][i];
		dp[i] %= mod;
		dp[i] += mod;
		dp[i] %= mod;
		dp[i] *= inv((1 - p[i] + mod) % mod);
		dp[i] %= mod;
		dp[i] += mod;
		dp[i] %= mod;
	}
	// for (int i = 0; i <= n; i++) cout << dp[i] << " ";
	// cout << endl;
	cout << dp[n] << endl;
	return 0;
}
//0 332748119 736482503 577613828
//0 332748119 736482503 879786027