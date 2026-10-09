#include <iostream>
#include <vector>
using namespace std;

const long long b = 32;

long long l, r, k;
long long dp[b][200][2]; // bit, sum, >=
long long z[b];

vector<long long> convert(long long a) {
	vector<long long> ret(b);
	for (long long i = b - 1; i >= 0; i--) {
		while (a >= z[i]) {
			ret[i]++;
			a -= z[i];
		}
	}
	return ret;
}

void clearDp() {
	for (long long i = 0; i < b; i++) for (long long j = 0; j < 200; j++) for (long long l = 0; l < 2; l++) {
		dp[i][j][l] = 0;
	}
}

long long doDp(long long u) { // u is upper bound exclusive
	clearDp();

	vector<long long> uz = convert(u);
	for (long long i = 0; i <= 4; i++) {
		dp[0][i][i >= uz[0]] = 1;
	}

	for (long long i = 1; i < b; i++) {
		for (long long sum = 0; sum < 200; sum++) {
			for (long long j = 0; j < 4; j++) {
				if (sum - j < 0) continue;
				dp[i][sum][j >= uz[i]] += dp[i - 1][sum - j][true];
				dp[i][sum][j > uz[i]] += dp[i - 1][sum - j][false];
			}
		}
		dp[i][4][4 >= uz[i]] += 1;
	}
	
	long long ans = 0;
	ans = dp[b - 1][k][false];
	// for (long long i = 0; i < b; i++) ans += dp[i][k][false];
	return ans;
}


void solve() {
	cin >> l >> r >> k;
	if (k >= 200) cout << 0 << endl;
	else cout << doDp(r + 1) - doDp(l) << endl;
}

int main() {
	long long t;
	cin >> t;
	z[0] = 1;
	for (long long i = 1; i < b; i++) z[i] = z[i - 1] * 4 + 1;
	while (t--) {
		solve();
	}
	return 0;
}

// s_i = 4
// s_j = 0 (j < i) 


// 1010100
// 101


// 1011001
// 1010101
// 1 x 4

// dp[i][j][k]    i bits, sum up to j, k is boolean which is true if last digit is 4