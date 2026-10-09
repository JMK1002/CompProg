#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

const long long mod = 1e9 + 7;

long long a, b, k;

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

void solve() {
	cin >> a >> b >> k;
	long long n = (a - 1) * k + 1;
	n %= mod;
	long long ch = 1;
	for (long long i = n; i > n - a; i--) {
		ch *= i;
		ch %= mod;
	}
	for (long long i = 1; i <= a; i++) {
		ch *= inv(i);
		ch %= mod;
	}
	long long m = ch * (b - 1) % mod * k % mod + 1;
	m %= mod;
	cout << n << " " << m << endl;
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