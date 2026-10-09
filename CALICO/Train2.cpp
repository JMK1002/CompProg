//
// Created by JMKov on 11/18/2023.
//
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    queue<int> blank;
    while (t--) {
        map<int, queue<int>> mps;
        set<pair<double, queue<int>>> psgs;
        int n, m, k;
        cin >> n >> m >> k;
        int s[n];
        int e[n];
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            s[i]--;
            mps[s[i]].emplace(i);
        }
        for (int i = 0; i < n; i++) {
            cin >> e[i];
            e[i]--;
        }
        for (pair<int, queue<int>> s : mps) psgs.insert(s);
        set<pair<int, int>> train;
        int t = -1;
        int ans = -1;
//        pair<int, queue<int>> asdf;
//        if (psgs.lower_bound(pair<int, queue<int>>{t, blank}) == psgs.end())
//            asdf = *psgs.lower_bound(pair<int, queue<int>>{0, blank});
//        else
//            asdf = *psgs.lower_bound(pair<int, queue<int>>{t, blank});
//        ans += (asdf.first - t + m) % m;
//        t = asdf.first;
        while (psgs.lower_bound(pair<int, queue<int>>{0, blank}) != psgs.end()) {
            while (train.size() < k) {
                pair<int, queue<int>> asdf;
                if (psgs.lower_bound(pair<int, queue<int>>{t, blank}) == psgs.end())
                    asdf = *psgs.lower_bound(pair<int, queue<int>>{0, blank});
                else
                    asdf = *psgs.lower_bound(pair<int, queue<int>>{t - 0.5, blank});
                ans += (asdf.first - t + m) % m;
                t = asdf.first;
                int ps = asdf.second.front();
                asdf.second.pop();
                train.emplace(e[ps], ps);
                if (asdf.second.empty()) {
                    psgs.erase(psgs.lower_bound(pair<int, queue<int>>{t, blank}));
                    if (psgs.empty()) break;
                }
            }
            while (!train.empty()) {
                ans += ((*train.begin()).first - t + m) % m;
                t = (*train.begin()).first;
                train.erase(train.begin());
            }
        }
        auto last = train.begin();
        for (int i = 1; i < train.size(); i++) last++;
        if (!train.empty()) ans += ((*(last)).first - t + m) % m;
        cout << ans << endl;
    }
    return 0;
}