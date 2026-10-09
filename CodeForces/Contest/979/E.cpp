#include <iostream>
using namespace std;

long long mod = 998244353;
long long fact[200005];
long long invFact[200006];
long long vals[200005];
long long cnt[200005];

long long inv(long long a) {
  return a <= 1 ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
    return fact[a] * invFact[b] % mod * invFact[a - b] % mod;
}

long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

void solve() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x;
        // cin >> x;
        x = i / 10;
        cnt[x]++;
    }
    long long ans = 0;
    long long mn = cnt[0];
    for (long long i = 0; i <= n; i++) vals[i] = 1;
    for (long long i = 0; i < n; i++) {
        long long k = binpow(2, cnt[i]) % mod;
        long long a = 0;
        for (long long j = 0; j < cnt[i]; j++) {
            ans *= 2;
            ans %= mod;
            if (j < mn) a += vals[j];
            a %= mod;
            ans += a;
            ans %= mod;
        }
        mn = min(cnt[i], mn);
        for (long long j = 0; j <= cnt[i]; j++) {
            k += mod;
            k -= choose(cnt[i], j) % mod;
            k %= mod;
            vals[j] *= k;
            vals[j] %= mod;
        }
    }
    ans %= mod;
    cout << ans << endl;

    for (long long i = 0; i <= n; i++) {
        cnt[i] = 0;
        vals[i] = 0;
    }
}

int main() {
    fact[0] = 1;
    invFact[0] = 1;
    for (long long i = 1; i < 200005; i++) {
        fact[i] = fact[i - 1] * i;
        fact[i] %= mod;
        invFact[i] = inv(fact[i]);
        invFact[i] %= mod;
    }

    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}