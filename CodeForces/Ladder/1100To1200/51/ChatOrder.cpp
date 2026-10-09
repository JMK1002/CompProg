//
// Created by JMKov on 3/23/2023.
//
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> init(n);
    vector<string> sorted(n);
    for (int i = 0; i < n; i++) {
        string b;
        cin >> b;
        init[i] = b;
    }
    map<string, bool> mp;
    for (int i = init.size() - 1; i >= 0; i--) {
        if (!mp[init[i]]) {
            cout << init[i] << endl;()
        }
        mp[init[i]] = true;
    }
    return 0;
}