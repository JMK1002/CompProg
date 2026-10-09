#include <iostream>
using namespace std;


int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long mx = 0;
        long long mn = 2000;
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            mx = max(mx, x);
            mn = min(mn, x);
        }
        cout << (n - 1) * (mx - mn) << endl;
    }
    return 0;
}