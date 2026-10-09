//
// Created by JMKov on 5/26/2024.
//
#include <iostream>
#include <map>

using namespace std;

map< , int> mp;

void solve() {
    int n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    string hsh[m];
    for (int i = 0; i < m; i++) hsh[i] = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            hsh[j] += arr[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        string s = hsh[i];
        for (int j = 0; j < n; j++) {
            s[j] = (s[j] == '1') ? '0' : '1';

            mp[s]++;

            s[j] = (s[j] == '1') ? '0' : '1';
        }
    }
    int ans = 0;
    string ansS = "";
    for (pair<string, int> p : mp) {
        if (p.second > ans) {
            ansS = p.first;
            ans = p.second;
        }
    }
    cout << ans << endl;
    cout << ansS << endl;
    mp.clear();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
