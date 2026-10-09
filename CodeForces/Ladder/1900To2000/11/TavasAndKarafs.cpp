//
// Created by JMKov on 7/24/2023.
//
#include <iostream>
using namespace std;

bool works(long long l, long long r, long long t, long long m, long long a, long long b) {
    if (a + (r - 1) * b > t) return false;
    long long sum = (r - l + 1) * a + ((r * (r - 1)) / 2 - ((l - 1) * (l - 2)) / 2) * b;
    return sum <= m * t;
}

long long solve(long long l, long long t, long long m, long long a, long long b) {
    if (!works(l, l, t, m, a, b)) return -1;
    long long low = l;
    long long high = 2000000;
    while (low < high) {
        long long mid = (low + high) / 2;
        if (works(l, mid, t, m, a, b)) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
//        cout << low << " " << high << endl;
    }
    low -= !works(l, low, t, m, a, b);
    return low;
}

int main() {
    long long a, b, n;
    cin >> a >> b >> n;
    while (n--) {
        long long l, t, m;
        cin >> l >> t >> m;
        cout << solve(l, t, m, a, b) << endl;
    }
    return 0;
}
// (2 * a + (l + r - 2) * b) * (r - l + 1) / 2 < t * m
// (2 * a + (l + r - 2) * b) * (r - l + 1) < 2 * t * m