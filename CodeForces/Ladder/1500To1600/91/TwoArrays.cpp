#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4;
const int MOD = 1e9+7;
typedef long long ll;
ll fact[MAX+1], invfact[MAX+1];

ll fastpow(ll base, int power) {
    if(power==0) return 1;
    ll res = fastpow(base, power/2);
    if(power%2==0) return res*res%MOD;
    return res*res%MOD*base%MOD;
}
ll modinv(ll base) {
    return fastpow(base, MOD-2);
}
int main() {
    fact[0] = 1, invfact[0] = 1;
    for(int i = 1; i<=MAX; i++) {
        fact[i] = fact[i-1]*i%MOD;
        invfact[i] = modinv(fact[i]);
    }
    int n, m; cin >> n >> m;
    cout << fact[n+2*m-1]*invfact[n-1]%MOD*invfact[2*m]%MOD << endl;
    return 0;
}