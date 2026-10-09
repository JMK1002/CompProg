#include <iostream>
#include <algorithm>
using namespace std;

long long n;
long long arr[100004];

void solve() {
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    long long gc = arr[0];
    long long g = __INT32_MAX__;
    for (long long i = 0; i < n; i++) {
        g = min(g, arr[i]);
        gc = __gcd(gc, arr[i]);
    }
    long long s = g;
    for (long long i = 0; i < min(n - 1, 10ll); i++) {
        long long ng = g;
        for (long long j = 0; j < n; j++) {
            ng = min(ng, __gcd(g, arr[j]));
        }
        g = ng;
        s += g;
    }
    s += (n - 1 - min(n - 1, 10ll)) * gc;
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