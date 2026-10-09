#include <iostream>
using namespace std;

long long mod = 998244353;

long long n, m;
string a, b;
long long needed[26];
long long chars[26];
long long dp[26][200005];
long long fact[200005];
long long invFact[200005];

long long inv(long long a) {
  return a <= 1ll ? a : mod - (long long)(mod/a) * inv(mod % a) % mod;
}

long long choose(long long a, long long b) {
    return fact[a] % mod * invFact[a - b] % mod * invFact[b] % mod;
}

int main() {
    fact[0] = 1;
    invFact[0] = 1;
    for (long long i = 1; i < 200005; i++) {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
        invFact[i] = inv(fact[i]);
        invFact[i] %= mod;
    }
    cin >> n >> m;
    cin >> a >> b;

    for (long long c : a) needed[c - 'A']++;
    for (long long c : b) chars[c - 'A']++;

    dp[25][needed[25]]++;
    for (long long j = 1; j < 200002; j++) {
        dp[25][j] += dp[25][j - 1];
    }
    for (long long i = 24; i >= 0; i--) {
        for (long long j = max(0ll, needed[i] - chars[i + 1]); j <= min(chars[i], needed[i]); j++) {
            dp[i][j] = dp[i + 1][chars[i + 1] - (needed[i] - j)] % mod * (choose(needed[i], j)) % mod;
        }
        for (long long j = 1; j <= 200002; j++) {
            dp[i][j] += dp[i][j - 1];
            dp[i][j] %= mod;
        }
    }
    long long ans = dp[0][200001] * fact[n] % mod;
    for (int i = 0; i < 26; i++) {
        ans *= invFact[needed[i]];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

// dp[i][j] = dp[i + 1][from 0 to `needed[j] - (needed[i] - j)] * (needed[i] choose j)