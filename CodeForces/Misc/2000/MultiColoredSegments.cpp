//
// Created by JMKov on 5/29/2024.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int INF = INT32_MAX;
int n;
pair<pair<int, int>, int> arr[200004];
set<pair<pair<int, int>, int>> events; // 0 is remove, 1 is insert
int lst = -1;
int prv = -1;
int ans[200004];
set<int> curr;
set<int> currCol[200004];

void st(int a, int b) {
    int d = max(0, arr[b].first.first - arr[a].first.second);
    ans[a] = min(ans[a], d);
    ans[b] = min(ans[b], d);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first.first >> arr[i].first.second >> arr[i].second;
        ans[i] = INF;
    }
    for (int asdf = 0; asdf < 2; asdf++) {
        for (int i = 0; i < n; i++) {
            events.insert({{arr[i].first.first, 0}, i});
            events.insert({{arr[i].first.second, 1}, i});
        }

        for (pair<pair<int, int>, int> e: events) {
            int ind = e.second;

            if (currCol[arr[ind].second].size() != curr.size()) {
                ans[ind] = 0;
            }
            if (e.first.second == 0) {
                curr.insert(ind);
                currCol[arr[ind].second].insert(ind);
            }
            else {
                curr.erase(ind);
                currCol[arr[ind].second].erase(ind);
            }

            if (lst != -1) {
                if (arr[lst].second == arr[ind].second) {
                    if (prv != -1) st(prv, ind);
                } else {
                    st(lst, ind);
                }
            }

            if (lst == -1) lst = ind;
            else if (arr[lst].second == arr[ind].second) {
                lst = ind;
            } else {
                prv = lst;
                lst = ind;
            }
        }

        for (int i = 0; i <= n; i++) {
            currCol[i].clear();
        }
        curr.clear();
        events.clear();
        prv = -1;
        lst = -1;

        for (int i = 0; i < n; i++) {
            arr[i].first.first *= -1;
            arr[i].first.second *= -1;
            swap(arr[i].first.first, arr[i].first.second);
        }
//        for (int i = 0; i < n; i++) cout << ans[i] << " ";
//        cout << endl;
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    for (int i = 0; i <= n; i++) {
        currCol[i].clear();
    }
    curr.clear();
    events.clear();
    prv = -1;
    lst = -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}