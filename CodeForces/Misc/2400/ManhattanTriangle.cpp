#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

int n, d;
set<pair<int, int>> pts;
map<pair<int, int>, int> mp;

void solve() {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pts.insert({x, y});
        mp[{x, y}] = i;
    }

    vector<pair<int, int>> ans;
    for (int po = 0; po < 2; po++) {
        set<pair<int, int>> thing; // {x + y, x};
        for (pair<int, int> p : pts) thing.insert({p.first - p.second, p.first});
        bool brr=0;
        for (pair<int, int> p : pts) {
            if (pts.find({p.first + d / 2, p.second + d / 2}) == pts.end()) continue;
            int a = p.first - p.second;
            auto ptr = thing.lower_bound({a + d, p.first + d / 2});
            if (!(ptr == thing.end() || ptr->first != a + d || ptr->second > p.first + d)) {
                ans.clear();
                ans.push_back(p);
                ans.push_back({p.first + d / 2, p.second + d / 2});
                ans.push_back({ptr->second, ptr->second - ptr->first});
                brr=1;
            }

            ptr = thing.lower_bound({a - d, p.first - d / 2});
            if (!(ptr == thing.end() || ptr->first != a - d || ptr->second > p.first)) {
                ans.clear();
                ans.push_back(p);
                ans.push_back({p.first + d / 2, p.second + d / 2});
                ans.push_back({ptr->second, ptr->second - ptr->first});
                brr=1;
            }
        }
        if (po && brr) for (int i = 0; i < 3; i++) ans[i].second *= -1;
        set<pair<int, int>> asdf;
        for (pair<int, int> p : pts) {
            asdf.insert({p.first, p.second * -1});
        }
        pts = asdf;
    }
    if (ans.empty()) {
        cout << "0 0 0" << endl;
    }
    else {
        for (pair<int, int> p : ans) cout << mp[p] + 1 << " ";
        cout << endl;
    }
    pts.clear();
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
// 1
// 3 2
// 0 0
// 1 1
// 1 3