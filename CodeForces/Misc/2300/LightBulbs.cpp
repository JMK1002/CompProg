//
// Created by JMKov on 6/27/2024.
//
#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <chrono>
#include <map>

using namespace std;

const long long mod = 998244353;

long long n;
long long last[500004];
long long randCol[500004];
long long col[500004];
long long events[500004];
map<long long, long long> mp;

mt19937 rng((long long) std::chrono::steady_clock::now().time_since_epoch().count());
long long rnd(long long x, long long y) {
    return uniform_int_distribution<long long>(x, y)(rng);
}

void solve() {
    cin >> n;
    for (long long i = 0; i < n * 2; i++) {
        cin >> col[i];
        col[i]--;
        last[col[i]] = i;
        randCol[col[i]] = rnd(1, 1985731459873142);
    }
    long long run = 0;
    for (long long i = 0; i < 2 * n; i++) {
        mp[run] = i + 1;
        run ^= randCol[col[i]];
        if (mp.find(run) != mp.end()) {
            events[mp[run] - 1]++;
            events[i + 1]--;
        }
    }

    long long ind = 0;
    long long cnt = 0;
    long long ans = 1;
    run = 0;
    while (ind < n * 2) {
        long long mx = ind;
        long long sz = 0;
        for (long long i = mx; i <= mx; i++) {
            mx = max(mx, last[col[i]]);
            run += events[i];
            sz += (run == 1);
        }
        ans *= sz;
        ans %= mod;
//        cout << sz << " ";
        cnt++;
        ind = mx + 1;
    }
//    cout << endl;
//    for (long long i : szs) cout << i << " ";
//    cout << endl;
    cout << cnt << " " << ans << endl;
    for (long long i = 0; i <= 2 * n; i++) {
        events[i] = 0;
        last[i] = 0;
        col[i] = 0;
    }
    mp.clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}