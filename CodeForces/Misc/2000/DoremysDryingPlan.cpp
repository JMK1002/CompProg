//
// Created by JMKov on 5/22/2024.
//
#include <iostream>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int n, m, k;
set<int> pre[200002];
int ones[200002];
map<pair<int, int>, int> mp;

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        pre[l].insert(i);
        pre[r + 1].insert(-i);
    }
    set<int> run;
    int zc = 0;
    for (int i = 0; i < n; i++) {
        for (int j : pre[i]) {
            if (j > 0) run.insert(j);
            else run.erase(j * -1);
        }
        if (run.empty()) {
            zc++;
        }
        if (run.size() == 1) {
            ones[*(run.begin())]++;
        }
        else if (run.size() == 2) {
            mp[{*(run.begin()), *(++run.begin())}]++;
        }
//        cout << run.size() << " ";
    }
//    cout << endl;
    int ans = 0;
    for (pair<pair<int, int>, int> p : mp) {
        ans = max(ans, ones[p.first.first] + ones[p.first.second] + p.second);
    }
    sort(ones, ones + (max(m, n) + 1));
    ans = max(ans, ones[max(m, n) - 1] + ones[max(m, n)]);
    cout << ans + zc << endl;

    for (int i = 0; i <= max(m, n); i++) {
        pre[i].clear();
        ones[i] = 0;
    }
    mp.clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}