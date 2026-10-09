//
// Created by JMKov on 5/18/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> top;
    vector<int> bottom;
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) continue;
        if (s1[i] == 'b') top.push_back(i);
        else bottom.push_back(i);
    }
    if ((top.size() % 2) != (bottom.size() % 2)) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i + 1 < bottom.size(); i += 2) {
        ans.emplace_back(bottom[i], bottom[i + 1]);
    }
    for (int i = 0; i + 1 < top.size(); i += 2) {
        ans.emplace_back(top[i], top[i + 1]);
    }
    if ((top.size() & 1) == 1) {
        ans.emplace_back(top[top.size() - 1], top[top.size() - 1]);
        ans.emplace_back(top[top.size() - 1], bottom[bottom.size() - 1]);
    }
    cout << ans.size() << endl;
    for (pair<int, int> p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    return 0;
}
//babbb
//abbbb