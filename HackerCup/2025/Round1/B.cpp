#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long cnt(long long n, long long val) {
	if (n == 1 || val == 1) return 1;
	long long sum = 0;
	vector<long long> primes;
	long long x = val;
	for (long long i = 2; x != 1; i++) {
		while (x % i == 0) {
			primes.push_back(i);
			x /= i;
		}
	}
	set<long long> divs;
	for (long long i = 0; i < primes.size(); i++) {
		set<long long> temp;
		for (long long j : divs) {
			temp.insert(j);
			temp.insert(j * primes[i]);
		}
		divs = temp;
	}

	for (long long i : divs) {
		sum += cnt(n / 2, i) * cnt(n - n / 2, val / i) % mod;
		sum %= mod;
	}

	return sum;
}

void solve() {
	long long n, a, b;
	cin >> n >> a >> b;
	long long sum = 0;
	for (long long i = 1; i * i <= b && i <= a; i++) {
		if (b % i != 0) continue;
		sum += cnt(n, i) * cnt(n, b / i) % mod;
		sum %= mod;
		if (i * i < b && b / i <= a) sum += cnt(n, b / i) * cnt(n, i) % mod;
		sum %= mod;
	}
	cout << sum << endl;
}

int main() {
	// ulimit -s unlimited
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t;
	cin >> t;
	long long cnt = 1;
	while (t--) {
		cout << "Case #" << cnt << ": ";
		solve();
		cnt++;
	}
	return 0;
}