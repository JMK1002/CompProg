#include <iostream>
#include <stack>
#include <set>
using namespace std;

const long long mod = 998244353;

long long n;
set<pair<int, int>>
long long fact[400000];
long long invFact[400000];

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
	return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

long long catalan(long long a) {
	return choose(2 * a, a) * inv(a + 1) % mod;
}

void solve() {
	cin >> n;
	for (long long i = 0; i <= n; i++) {
		if (i != 0) {
			long long l, r;
			cin >> l >> r;
			l--; r--;
			arr[l] = 1;
			arr[r] = 2;
		}
		stack<long long> st;
		long long ans = 1;
		for (long long j = 0; j < 2 * n; j++) {
			if (arr[j] == 2) {
				long long cnt = 0;
				while (arr[st.top()] == 0) {
					cnt++;
					st.pop();
				}
				// Popping the opening parenthesis
				st.pop();
				ans *= catalan(cnt / 2);
				ans %= mod;
			}
			else {
				st.push(j);
			}
		}
		ans *= catalan(st.size() / 2);
		ans %= mod;
		cout << ans << " ";
	}
	cout << endl;
	for (int i = 0; i <= 2 * n; i++) {
		arr[i] = 0;
	}
}

int main() {
	long long t;
	cin >> t;
	fact[0] = 1;
	for (long long i = 1; i < 400000; i++) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
	}
	for (long long i = 0; i < 400000; i++) invFact[i] = inv(fact[i]) % mod;
	while (t--) {
		solve();
	}
	return 0;
}