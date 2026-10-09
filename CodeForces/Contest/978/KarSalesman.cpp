#include <iostream>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;
        long long s = 0;
        long long mx = 0;
        for (long long i = 0; i < n; i++) {
            long long a;
            cin >> a;
            s += a;
            mx = max(a, mx);
        }
        cout << max(mx, s / x + (s % x != 0)) << endl;
    }
    return 0;
}