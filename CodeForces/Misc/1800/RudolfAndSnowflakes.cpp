//
// Created by JMKov on 4/29/2024.
//
#include <iostream>
#include <map>
#include <cmath>

using namespace std;


bool pfsq(long long k) {
    long long low = 0;
    long long high = 2000000000;
    while (high - low > 1) {
        long long mid = (low + high) / 2;
        if (mid * mid == k) return true;
        else if (mid * mid < k) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    return (low * low) == k;
}

int main() {
    long long t;
    cin >> t;
    map<long long, bool> mp;
    for (long long i = 2; i < 1000004; i++) {
        long long s = 1 + i + i * i;
        long long rn = i * i * i;
        while (INT64_MAX - s >= rn && rn <= INT64_MAX / i) {
            s += rn;
            mp[s] = true;
            rn *= i;
        }
//        if (i == 2) cout << s << endl;
        s += rn;
        mp[s] = true;
        rn *= i;
    }
//    cout << mp.size() << endl;
//    cout << mp[3] << " " << mp[7] << " " << mp[15] << " " << mp[31] << " " << mp[4294967295] << endl;
    while (t--) {
        long long x;
        cin >> x;
//        x = (long long) pow(2, 59) - 1;
//        cout << x << endl;
        bool y = pfsq(4 * x - 3);
        if (x < 7) cout << "NO" << endl;
        else cout << ((y || mp[x]) ? "YES" : "NO") << endl;
    }
    return 0;
}