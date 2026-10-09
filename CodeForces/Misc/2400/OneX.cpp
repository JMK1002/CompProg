#include <iostream>
#include <map>
using namespace std;

long long mod = 998244353;

long long n;
map<long long, long long> dp;

long long binpow(long long a, long long b) {
	long long run = a;
	long long res = 1;
	while (b) {
		if (b & 1) res *= run;
		res %= mod;
		b >>= 1;
		run *= run;
		run %= mod;
	}
	return res;
}

long long get(long long v) {
	
}

void solve() {
	cin >> n;
	cout << get(n) << endl;
}

int main() {
	long long t;
	cin >> t;
	dp[1] = 1;
	while (t--) {
		solve();
	}
	return 0;
}

// dp[i] is the val for n=i
// 
// i is even: dp[i] = (4i + 1) * dp[i / 2] + (2^(i/2) - 1)^2
// i is odd: dp[i] = (2i) * dp[i / 2 + 1] + (2i + 1) * dp[i / 2] + (2^(i/2) - 1) * (2^(i/2 + 1) - 1)
// dp[1] = 1