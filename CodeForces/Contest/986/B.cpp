#include <iostream>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    long long t;
    cin >> t;
    while (t--) {
        long long n, b, c;
        cin >> n >> b >> c;
        if (b == 0 && n - c > 2) {
            cout << -1 << endl;
            continue;
        }
        else if (b == 0 && c < n) {
            cout << n - 1 << endl;
            continue;
        }
        else if (b == 0) {
            cout << n << endl;
            continue;
        }
        long long x = (n - 1 - c) / b + 1;
        if (c >= n) x = 0;
        // cout << ((x - 1) * b + c - n) << " " << x << endl;
        cout << n - x << endl;
    }
    return 0;
}