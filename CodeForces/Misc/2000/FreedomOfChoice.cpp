//
// Created by JMKov on 5/19/2024.
//
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

long long m;
long long ni[100004];
pair<long long, long long> rs[100004];
vector<long long> a[100004];
vector<long long> c[100004];
long long sum[100004];
set<long long> check;
map<long long, vector<pair<long long, long long>>> inv;

void clean() {
    for (long long i = 0; i < m; i++) {
        a[i].clear();
        c[i].clear();
        sum[i] = 0;
        ni[i] = 0;
    }
    check.clear();
    inv.clear();
}

void solve() {
    cin >> m;
    long long l = 0;
    long long h = 0;

    for (long long i = 0; i < m; i++) {
        cin >> ni[i] >> rs[i].first >> rs[i].second;
        l += rs[i].first;
        h += rs[i].second;
//        rs[i].first--; rs[i].second--;
        for (long long j = 0; j < ni[i]; j++) {
            long long x;
            cin >> x;
            a[i].push_back(x);
        }
        for (long long j = 0; j < ni[i]; j++) {
            long long x;
            cin >> x;
            c[i].push_back(x);
            sum[i] += x;
        }
    }
    for (long long i = 0; i < m; i++) {
        for (long long j = 0; j < ni[i]; j++) {
            if (a[i][j] >= l && a[i][j] <= h) {
                check.insert(a[i][j]);
                inv[a[i][j]].push_back({max((long long) 0, rs[i].first - (sum[i] - c[i][j])), max((long long) 0, rs[i].second - (sum[i] - c[i][j]))}); // Maybe lower bound is important
            }
        }
    }
    long long ans = INT64_MAX;
    for (long long i = l; i <= h; i++) {
        long long sh = 0;
        long long sl = 0;
        for (pair<long long, long long> j : inv[i]) {
            sl += j.first;
            sh += j.second;
        }
        long long cand = max(sl, sh - (h - i));
        ans = min(ans, cand);
//        cout << i << "a" << cand << " ";
        if (!ans) break;
    }
//    cout << endl;
    cout << ans << endl;
    clean();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}