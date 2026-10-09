#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long n;
long long arr[200005];

void solve() {
	cin >> n;
	long long s = 0;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
		s += arr[i];
		s %= mod;
	}
	s *= s;
	s %= mod;
	for (long long i = 0; i < n; i++) {
		s -= arr[i] * arr[i] % mod;
		s %= mod;
	}
	
	s += mod;
	s %= mod;
	s *= inv(2);
	s %= mod;
	s *= inv(n * (n - 1) / 2 % mod);
	s %= mod;
	cout << s << endl;
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