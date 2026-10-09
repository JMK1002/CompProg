//
// Created by JMKov on 7/28/2023.
//
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

map<string, set<int>> mp;
map<string, int> restricted;
string arr[1002];
bool ans[1002];

int check(int i) {
    string a = arr[i].substr(0, 3);
    string b = arr[i].substr(0, 2) + arr[i][3];
    if (a == b) {
        return false;
    }
    if (restricted[a] == -1) {
        return false;
    }
    if (!mp[a].empty()) {
        for (int j: mp[a]) {
            if (i == j) continue;
            if (!check(j)) {
                return false;
            }
        }

        mp[a].clear();
    }
    ans[i] = true;
    return true;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string u, v;
        cin >> u >> v;
        arr[i] = u.substr(0, 3) + v.substr(0, 1);
    }
//    sort(arr, arr + n);
    for (int i = 0; i < n; i++) {
        string s = arr[i].substr(0, 3);
        if (restricted[s] != 0) {
            restricted[s] = -1;
        }
        else {
            restricted[s] = i + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        string a = arr[i].substr(0, 3);
        string b = arr[i].substr(0, 2) + arr[i][3];
        if (!mp[b].empty()) {
            for (int j : mp[b]) {
                if (!check(j)) {
                    if (!check(i)) {
                        cout << "NO" << endl;
                        return 0;
                    }
                    break;
                }
            }
            mp[b].clear();
        }
        mp[b].insert(i);
    }
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        string a = arr[i].substr(0, 3);
        string b = arr[i].substr(0, 2) + arr[i][3];
        cout << (ans[i] ? a : b) << endl;
    }
    return 0;
}
// if two teams have the same arr[i], then it is impossible

//ABCD
//ABEC
//ABED
//3
//ABC D
//ABE D
//ABE F