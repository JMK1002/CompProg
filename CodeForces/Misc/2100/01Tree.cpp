//
// Created by JMKov on 6/26/2024.
//
#include <iostream>
#include <set>
#include <queue>

using namespace std;

int n;
int arr[200004];
int par[200004];
set<pair<int, pair<int, int>>> mx;
set<pair<pair<int, int>, int>> vals;

void combine(pair<pair<int, int>, int> p) {
    if (vals.size() == 1) return;
    pair<pair<int, int>, int> nxt, prev;
    if (p.first.first == 0) {
        nxt = *(++vals.begin());
        prev = {{-100, -100}, -100};
    }
    else if (p.first.second == n - 1) {
        nxt = {{-100, -100}, -100};
        prev = *(--(--vals.end()));
    }
    else {
        nxt = *vals.lower_bound({p.first, 1000000000});
        prev = *(--vals.lower_bound({p.first, -1}));
    }

    if (abs(nxt.second - p.second) == 1 || abs(prev.second - p.second) == 1) {
        pair<pair<int, int>, int> other;
        if (abs(nxt.second - p.second) == 1) other = nxt;
        else other = prev;

        mx.erase({p.second, p.first});
        mx.erase({other.second, other.first});
        vals.erase(p);
        vals.erase(other);
        pair<pair<int, int>, int> nw = {{min(p.first.first, other.first.first), max(p.first.second, other.first.second)}, min(p.second, other.second)};
        mx.insert({nw.second, nw.first});
        vals.insert(nw);
        if ((*mx.begin()).first == nw.second) combine(nw);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
//        arr[i] = (i != 0);
        par[i] = i;
        vals.insert({{i, i}, arr[i]});
        mx.insert({arr[i], {i, i}});
    }
    int sz = 10000000;
    while (sz != mx.size()) {
        sz = mx.size();
        int val = (*(--mx.end())).first;

        auto ptr = mx.end();
        while (sz == mx.size() && mx.begin() != ptr) {
            ptr--;
            if ((*ptr).first != val) break;
            combine({(*ptr).second, (*ptr).first});
        }
    }
    if (mx.size() == 1 && (*mx.begin()).first == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        par[i] = 0;
    }
    mx.clear();
    vals.clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
