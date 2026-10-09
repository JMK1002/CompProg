#include <bits/stdc++.h>
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int MAX_N = 1e6 + 3;
bitset<MAX_N> isprime;
vector<int> primes;
 
vector<int> eratosthenesSieve(int lim) {
    isprime.set();
    isprime[0] = isprime[1] = false;
    for (int i = 4; i < lim; i += 2) isprime[i] = false;
    for (int i = 3; i * i < lim; i += 2)
        if (isprime[i])
            for (int j = i * i; j < lim; j += i * 2) isprime[j] = false;
    vector<int> pr;
    for (int i = 2; i < lim; i++)
        if (isprime[i]) pr.push_back(i);
    return pr;
}
 
vector<int> ans(MAX_N, 0);
 
signed main() {
    primes = eratosthenesSieve(MAX_N);
    vector<int> del(MAX_N, 0);
    // Handle the contribution for all primes
    for (auto &p: primes) {
        for (int curr = p; curr < MAX_N; curr += p) {
            int inc = (p - ((curr / p) % p)) % p;
            del[curr] = (del[curr] + inc) % MOD;
            if (curr + p < MAX_N) del[curr + p] = (del[curr + p] - inc + MOD) % MOD;
        }
    }
    //Special case of 4
    for (int curr = 4; curr < MAX_N; curr += 4) {
        int inc = (2 * (curr / 4)) % 4;
        del[curr] = (del[curr] + inc) % MOD;
        if (curr + 4 < MAX_N) del[curr + 4] = (del[curr + 4] - inc + MOD) % MOD;
    }
    int pref = 0;
    for (int i = 1; i < MAX_N; i++) {
        pref = (pref + del[i]) % MOD;
        ans[i] = (ans[i - 1] + pref) % MOD;
    }
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }
}