//
// Created by JMKov on 6/14/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int prev(int v) {
    return (v - 1 + n) % n;
}

int next(int v) {
    return (v + 1) % n;
}

void solve() {
    string s;
    cin >> n >> s;
    int ind = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '1' && s[i] == '0') {
            ind = i;
            break;
        }
    }

    if (count(s.begin(), s.end(), '0') == n || count(s.begin(), s.end(), '1') & 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;

    vector<pair<int, int>> ans;
    for (int i = next(ind); i != ind; i = next(i)) {
        if (s[prev(i)] == '1') {
            ans.emplace_back(ind, i);
        }
        else {
            ans.emplace_back(prev(i), i);
        }
    }
    for (pair<int, int> p : ans) cout << p.first + 1 << " " << p.second + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
