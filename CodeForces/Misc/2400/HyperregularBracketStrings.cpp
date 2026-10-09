#include <iostream>
#include <set>
#include <vector>
#include <chrono>
#include <map>
using namespace std;

const long long mod = 998244353;

struct custom_hash {
    static long long splitmix64(long long x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    long long operator()(long long x) const {
        static const long long FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

long long inv(long long a) {
	return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long n, k;
set<long long> l[300005];
set<long long> r[300005];
long long cat[300005];
map<long long, long long> cnt;
custom_hash hash_func;

void solve() {
	cin >> n >> k;
	for (long long i = 0; i < k; i++) {
		long long u, v;
		cin >> u >> v;
		l[u].insert(i);
		r[v].insert(i);
	}
	long long run = 0;
	for (long long i = 1; i <= n; i++) {
		for (long long j : l[i]) run ^= hash_func(j);
		cnt[run]++;
		for (long long j : r[i]) run ^= hash_func(j);
	}
	long long ans = 1;
	for (pair<long long, long long> p : cnt) {
		ans *= cat[p.second];
		ans %= mod;
	}
	cout << ans << endl;
	for (int i = 0; i <= n + 1; i++) {
		l[i].clear();
		r[i].clear();
	}
	cnt.clear();
}

int main() {
	istream::sync_with_stdio(0);
	cin.tie(nullptr);
	cat[0] = 1;
	for (long long i = 2; i < 300005; i += 2) {
		cat[i] = cat[i - 2] * 2 * (i - 1) % mod * inv(i / 2 + 1) % mod;
	}
	long long t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
