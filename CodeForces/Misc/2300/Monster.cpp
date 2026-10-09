#include <iostream>
using namespace std;

long long x, y, z, k;

long long getDmg(long long a, long long b) {
    long long c = max(0ll, (a - 1) / k);
    if (c > b) {
        return b * (b + 1) / 2 * k;
    }
    b -= c;
    return c * (c + 1) / 2 * k + a * b;
}

long long getCost(long long a, long long b) {
    return a * x + b * y;
}

void solve() {
    cin >> x >> y >> z >> k;
    long long ans = 1000000000000000000;
    for (long long i = 1; i * i <= z * 2; i++) {
        long long low = 0;
        long long high = z + 10;
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (getDmg(i, mid) >= z) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        if (getDmg(i, high) < z) continue;
        // cout << getDmg(i, high) << " " << getCost(i, high) << " " << i << " " << high << endl;
        ans = min(ans, getCost(i, high));
    }
    for (long long i = 1; i * i <= z * 2; i++) {
        long long low = 0;
        long long high = z + 10;
        while (high - low > 1) {
            long long mid = (low + high) / 2;
            if (getDmg(mid, i) >= z) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        if (getDmg(high, i) < z) continue;
        // cout << getDmg(high, i) << " " << getCost(high, i) << " " << high << " " << i << endl;
        ans = min(ans, getCost(high, i));
    }
    cout << ans << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}