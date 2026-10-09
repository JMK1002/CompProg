//
// Created by JMKov on 6/15/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int tot, n;
pair<int, int> arr[502];
vector<pair<int, int>> additions;
set<int> vals;
map<int, set<int>> cnt;
vector<int> ans;

void clean() {
    for (int i = 0; i <= n; i++) {
        arr[i] = {0, 0};
    }
    additions.clear();
    vals.clear();
    cnt.clear();
    ans.clear();
    tot = 0;
}

void reflect(int ind) {
    for (int i = 0; i < ind; i++) {
        additions.push_back({tot + (ind) + i, arr[i].first});
    }

    for (int i = 0; i < ind; i++) {
        pair<int, int> a = arr[i];
        if (a.second >= ind) arr[a.second].second = ind - (i) - 1;
        else {
            arr[i].second = ind - (a.second) - 1;
        }
    }
    for (int i = 0; i < ind / 2; i++) {
        swap(arr[i], arr[ind - (i) - 1]);
    }

    tot += (ind) * 2;
    ans.push_back((ind) * 2);
}

void moveToBack(int ind, int b) {
    reflect(ind + 1);
    reflect(b + 1);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        cnt[arr[i].first].insert(i);
        vals.insert(arr[i].first);
    }

    for (int v : vals) {
        if (cnt[v].size() % 2 == 1) {
            cout << -1 << endl;
            clean();
            return;
        }
        auto ptr = cnt[v].begin();
        while (ptr != cnt[v].end()) {
            int a = *ptr;
            ptr++;
            int b = *ptr;
            ptr++;

            arr[a].second = b;
            arr[b].second = a;
        }
    }
//    reflect(1);
//    for (int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << endl;
//    cout << endl;
//
//    for (int i = 0; i < n; i++) cout << arr[i].first << " " << arr[i].second << endl;
//    cout << endl;
    for (int i = n - 1; i >= n / 2; i--) {
        for (int j = 0; j <= i; j++) {
            if (arr[j].second > i) continue;
            moveToBack(j, i);
            break;
        }
    }
    for (int i = 0; i < n / 2; i++) {
        moveToBack(arr[n - 1 - i].second, n / 2 - i - 1);
    }
    ans.push_back(n);
    cout << additions.size() << endl;
    for (pair<int, int> p : additions) cout << p.first << " " << p.second << endl;
    cout << ans.size() << endl;
    for (int i : ans) cout << i << " ";
    cout << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
