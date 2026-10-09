#include <iostream>
using namespace std;

long long n, m, x;
long long arr[1004][1004];
long long pre[1004][1004];

long long binpow(long long a, long long b) {
	long long res = 1;
	long long run = a;
	while (b) {
		if (b & 1) res *= run;
		run *= run;
		b >>= 1;
	}
	return res;
}

void solve() {
	cin >> n >> m >> x;
	for (long long i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (long long j = 0; j < m; j++) arr[i][j] = s[j] - '0';
	}

	bool works = true;

	for (long long i = 0; i < n - 1; i++) {
		for (long long j = 0; j < m - 1; j++) {
			long long val = binpow(arr[i][j] - arr[i + 1][j], x) +
			binpow(arr[i + 1][j] - arr[i + 1][j + 1], x) +
			binpow(arr[i + 1][j + 1] - arr[i][j + 1], x) +
			binpow(arr[i][j + 1] - arr[i][j], x);

			if (val != 0) {
				works = false;
			}
		}
	}

	for (long long i = 1; i < m; i++) pre[0][i] = pre[0][i - 1] + binpow(arr[0][i - 1] - arr[0][i], x);
	for (long long i = 1; i < n; i++) for (long long j = 0; j < m; j++) {
		pre[i][j] = pre[i - 1][j] + binpow(arr[i - 1][j] - arr[i][j], x);
	}

	long long q;
	cin >> q;
	while (q--) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		if (!works) {
			cout << "INVALID" << endl;
			continue;
		}
		cout << pre[c][d] - pre[a][b] << endl;

	}
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	long long t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}