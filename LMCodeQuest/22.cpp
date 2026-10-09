//
// Created by JMKov on 2/24/2024.
//
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    map<string, vector<string>> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        vector<string> v;
        for (int j = 0; j < 6; j++) {
            string s2;
            cin >> s2;
            v.push_back(s2);
        }
        mp[s] = v;
    }

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        vector<int> v;
        for (int j = 0; j < 6; j++) {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        map<string, int> mp2;
        for (int j = 0; j < 6; j++) {
            mp2[mp[s][j]] = v[j];
        }
        cout << s << endl;
        cout << "STR: " << mp2["STR"] << endl;
        cout << "DEX: " << mp2["DEX"] << endl;
        cout << "CON: " << mp2["CON"] << endl;
        cout << "INT: " << mp2["INT"] << endl;
        cout << "WIS: " << mp2["WIS"] << endl;
        cout << "CHA: " << mp2["CHA"] << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}