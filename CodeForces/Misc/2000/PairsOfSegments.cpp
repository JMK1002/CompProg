//
// Created by JMKov on 3/8/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    multiset<pair<long long, long long>> segs;
    multiset<pair<long long, long long>> un;
    for (long long i = 0; i < n; i++) {
        long long u, v;
        cin >> u >> v;
        for (pair<long long, long long> p : segs) {
            if (u <= p.second && u >= p.first ||
                    v <= p.second && v >= p.first ||
                    p.first <= v && p.first >= u ||
                    p.second <= v && p.second >= u) {
                un.emplace(min(u, p.first), max(v, p.second));
            }
        }
        segs.emplace(u, v);
    }
//    for (pair<long long, long long> p : un) cout << p.first << " " << p.second << endl;

    set<pair<long long, long long>> queue;
    long long mx = 0;
    for (pair<long long, long long> p : un) {
        while (!queue.empty() && (*queue.begin()).first <= p.first - 1) {
            mx = max(mx, (*queue.begin()).second);
            queue.erase(queue.begin());
        }
        queue.emplace(p.second, mx + 1);
    }
    for (pair<long long, long long> p : queue) mx = max(mx, p.second);
    cout << n - 2 * (mx) << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}