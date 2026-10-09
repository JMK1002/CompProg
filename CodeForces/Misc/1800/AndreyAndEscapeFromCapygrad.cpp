//
// Created by JMKov on 4/23/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<pair<pair<int, int>, int>> ev; // events
pair<pair<int, int>, pair<int, int>> arr[200004];
int x[200004];
int ans[200004];
set<int> in; // portals currently in
set<int> chng;

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].second.second
        >> arr[i].first.second >> arr[i].second.first;
        ev.insert({{arr[i].first.first, 0}, i});
        ev.insert({{arr[i].second.first, 2}, i});
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> x[i];
        ans[i] = x[i];
        ev.insert({{x[i], 1}, i});
    }
    int mx = 0;
    int lst = -1;
    for (pair<pair<int, int>, int> p : ev) {
        if (lst != p.first.first && in.empty()) {
            for (int i : chng) ans[i] = max(mx, ans[i]);
            chng.clear();
        }
        if (p.first.second == 0) {
            in.insert(p.second);
            mx = max(mx, arr[p.second].second.first);
        }
        if (p.first.second == 1) {
            chng.insert(p.second);
        }
        if (p.first.second == 2) {
            in.erase(p.second);
        }
        lst = p.first.first;
    }
    for (int i : chng) ans[i] = max(mx, ans[i]);
    for (int i = 0; i < k; i++) cout << ans[i] << " ";
    cout << endl;

    ev.clear();
    in.clear();
    chng.clear();
    for (int i = 0; i < k; i++) ans[i] = 0;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}