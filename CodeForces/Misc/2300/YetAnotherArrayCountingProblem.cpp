#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

struct Tree {
	typedef pair<long long, long long> T; // ! {value, index}
	static constexpr T unit = {LONG_LONG_MIN, LONG_LONG_MIN};

    // * F is defined as leftmost max
	T f(T a, T b) { 
        if (a.first == b.first) return min(a, b);
        return max(a, b); 
    } // (any associative fn)


	vector<T> s; long long n;

	Tree(long long n = 0, T def = unit) : s(2*n, def), n(n) {}

	void update(long long pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(long long b, long long e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

const long long mod = 1000000007;

long long n, m;
long long arr[200005];
pair<long long, long long> children[200005];
vector<long long> dp[200005];
Tree t;

// * Left inclusive right exclusive
long long dfs(long long l, long long r) {
    if (l == r) return 200004;
    long long ind = t.query(l, r).second;
    children[ind] = {dfs(l, ind), dfs(ind + 1, r)};
    long long a = dp[children[ind].first][0];
    long long b = dp[children[ind].second][0];
    for (long long i = 1; i <= m; i++) {
        b += dp[children[ind].second][i];
        b %= mod;
        dp[ind][i] = a * b;
        dp[ind][i] %= mod;
        a += dp[children[ind].first][i];
        a %= mod;
    }
    return ind;
}

void solve() {
    cin >> n >> m;
    t = Tree(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        t.update(i, {arr[i], i});
        children[i] = {200004, 200004};
        for (long long j = 0; j <= m; j++) dp[i].push_back(0);
    }
    for (long long i = 0; i <= m; i++) dp[200004].push_back(0);
    dp[200004][0] = 1;

    long long root = t.query(0, n).second;
    dfs(0, n);
    long long ans = 0;
    for (long long i = 1; i <= m; i++) {
        ans += dp[root][i];
        ans %= mod;
    }
    cout << ans << endl;

    for (long long i = 0; i <= n; i++) {
        children[i] = {0, 0};
        dp[i].clear();
        arr[i] = 0;
    }
    dp[200004].clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}