//
// Created by JMKov on 7/15/2024.
//
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, k, x;
bool explored[200005];
vector<set<int>> ans;

void clean() {
    for (int i = 0; i <= n; i++) explored[i] = false;
    ans.clear();
}

void solve() {
    cin >> n >> k >> x;
    for (int i = n; i >= 1; i--) {
        if ((i ^ x) >= n || explored[i ^ x]) continue;
        set<int> st;
        explored[i] = true;
        explored[i ^ x] = true;
        st.insert(i);
        if ((i ^ x) != 0) st.insert(i ^ x);
        ans.push_back(st);
    }
    int s = 0;
    for (int i = 1; i <= n; i++) if (!explored[i]) s ^= i;
    if (!(s == x || s == 0)) {
        cout << "NO" << endl;
        clean();
        return;
    }
    set<int> st;
    for (int i = 1; i <= n; i++) if (!explored[i]) st.insert(i);
    ans.push_back(st);
    if (k % 2 == (ans.size() + (s == 0)) % 2 && k <= ans.size()) {
        cout << "YES" << endl;
        for (int i = 0; i < k - 1; i++) {
            cout << ans[i].size() << " ";
            for (int j : ans[i]) cout << j << " ";
            cout << endl;
        }
        int asdf = 0;
        for (int i = k - 1; i < ans.size(); i++) asdf += ans[i].size();
        cout << asdf << " ";
        for (int i = k - 1; i < ans.size(); i++) {
            for (int j : ans[i]) cout << j << " ";
        }
        cout << endl;
    }
    else cout << "NO" << endl;
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