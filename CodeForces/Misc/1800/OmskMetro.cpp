//
// Created by JMKov on 5/5/2024.
//
#include <iostream>
using namespace std;



void solve() {
    int n;
    cin >> n;
    int par[n];
    pair<int, int> bound[n];
    pair<int, int> pre[n];
    par[0] = 0;
    bound[0] = {0, 1};
    pre[0] = {0, 1};
    int ind = 1;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '?') {
            int u, v, k;
            cin >> u >> v >> k;
            v--;
//            cout << pre[v].first << " " << pre[v].second << endl;
            if (pre[v].first <= k && k <= pre[v].second) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else {
            int x;
            cin >> par[ind] >> x;
            par[ind]--;
            bound[ind] = {bound[par[ind]].first + (x == 1) - (x != 1), bound[par[ind]].second + (x == 1) - (x != 1)};
            bound[ind].first = min(bound[ind].first, 0);
            bound[ind].second = max(bound[ind].second, 0);
            pre[ind].first = min(pre[par[ind]].first, bound[ind].first);
            pre[ind].second = max(pre[par[ind]].second, bound[ind].second);
            ind++;
        }
    }
//    for (pair<int, int> p : bound) cout << p.first << " " << p.second << endl;
//    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}