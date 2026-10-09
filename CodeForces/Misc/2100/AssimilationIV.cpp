#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mod = 998244353;

int n, m;
vector<int> dists[50005];
long long fact[22];

long long inv(int a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	fact[0] = 1;
	for (int i = 1; i < 22; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			dists[j].push_back(x);
		}
	}
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		sort(dists[i].begin(), dists[i].end());
		long long run = 1;
		for (int j = 0; j < n; j++) {
			if (j != 0 && dists[i][j - 1] <= j) run = 0;
			if (j != 0) run *= (dists[i][j - 1] - 1) - (j - 1);
			run %= mod;

			ans += run * (n - dists[i][j] + 1) % mod * fact[n - j - 1] % mod;
			ans %= mod;
		}
	}
	ans *= inv(fact[n]);
	ans %= mod;
	cout << ans << endl;
	return 0;
}