#include <iostream>
#include <map>
using namespace std;

long long p;

long long arr[300005];
long long asdf[300005];

long long inv(long long a) {
    return a <= 1 ? a : p - (long long)(p/a) * inv(p % a) % p;
}

int main() {
    long long n, k;
    cin >> n >> p >> k;
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
        asdf[i] = 1;
        
        for (long long  j =0 ; j < 3; j++) {
            asdf[i] *= arr[i];
            asdf[i] %= p;
        }
        mp[asdf[i]]++;
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++) if (asdf[i]) ans += mp[inv(asdf[i]) * k % p] - (inv(asdf[i]) * k % p == asdf[i]);
    ans /= 2;
    cout << ans << endl;
    return 0;
}