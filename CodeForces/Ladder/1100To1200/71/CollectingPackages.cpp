//
// Created by JMKov on 3/29/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<pair<int, int>> packages(n);
        for (int i = 0; i < n; i++) {
            pair<int, int> package;
            int a, b;
            cin >> package.first >> package.second;
            packages[i] = package;
        }
        sort(packages.begin(), packages.end(), compare);
        int lastHeight = 0;
        bool possible = true;
        for (auto& package : packages) {
            //cout << package.first << " " << package.second << "SDFDSFSF" << endl;
            if (package.second < lastHeight) {
                possible = false;
                cout << "NO" << endl;
                break;
            }
            lastHeight = package.second;
        }
        if (!possible) {
            continue;
        }
        cout << "YES" << endl;
        string s = "";
        int x = 0;
        int y = 0;
        for (auto& package : packages) {
            for (x; x < package.first; x++) {
                s += "R";
            }
            for (y; y < package.second; y++) {
                s += "U";
            }
        }
        cout << s << endl;
    }
    return 0;
}