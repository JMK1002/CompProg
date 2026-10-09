#include <iostream>
using namespace std;

long long amnt(long long n, long long k) {
    if (n < k) return 0;
    else if (n % 2 == 0) {
        return 2 * amnt(n / 2, k);
    }
    else {
        return 1 + 2 * amnt(n / 2, k);
    }
}

long long ans(long long n, long long k) {
    if (n < k) return 0;
    if (n % 2 == 0) {
        return 2 * ans(n / 2, k) + (n / 2) * amnt(n / 2, k);
    }
    else {
        return n / 2 + 1 + 2 * ans(n / 2, k) + (n / 2 + 1) * amnt(n / 2, k);
    }
}

void solve() {
    long long n, k;
    cin >> n >> k;
    cout << ans(n, k) << endl;
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