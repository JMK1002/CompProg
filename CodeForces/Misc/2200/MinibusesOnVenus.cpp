#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

long long n, mod, k;
long long cnt[102][32];
vector<long long> moves;

void fill() {
	cnt[0][0] = 1;
	for (long long i = 1; i <= n; i++) {
		for (long long sum = 0; sum < k; sum++) {
			cnt[i][sum] = 0;
			for (long long j : moves) {
				cnt[i][sum] += cnt[i - 1][(sum - j + k) % k];
				cnt[i][sum] %= mod;
			}
		}
	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> n >> k >> mod;
	long long ans = 1;
	for (long long i = 0; i < n; i++) {
		ans *= k;
		ans %= mod;
	}
	for (long long i = 0; i < k; i++) {
		for (long long j = 0; j < k; j++) {
			if (j * 2 % k == i) continue;
			moves.push_back(j);
		}
		fill();
		moves.clear();

		ans += mod - cnt[n][i];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}