//
// Created by JMKov on 7/25/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int, pair<int, pair<int, int>>> s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second.first >> s[i].second.second.first;
        s[i].second.second.second = i;
    }
    sort(s, s + n);
    bool taken[n];
    for (bool & i : taken) i = false;
    for (int i = 1; i < n; i++) {
        if (taken[s[i].second.second.second]) continue;
        int p = i - 1;
        while (p >= 0 && taken[s[p].second.second.second]) p--;
        if (p == -1) continue;
        if (s[i].first == s[p].first && s[i].second.first == s[p].second.first) {
            cout << s[i].second.second.second + 1 << " " << s[p].second.second.second + 1 << endl;
            taken[s[i].second.second.second] = true;
            taken[s[p].second.second.second] = true;
        }
    }
    for (int i = 1; i < n; i++) {
        if (taken[s[i].second.second.second]) continue;
        int p = i - 1;
        while (p >= 0 && taken[s[p].second.second.second]) p--;
        if (p == -1) continue;
        if (s[i].first == s[p].first) {
            cout << s[i].second.second.second + 1 << " " << s[p].second.second.second + 1 << endl;
            taken[s[i].second.second.second] = true;
            taken[s[p].second.second.second] = true;
        }
    }
    for (int i = 1; i < n; i++) {
        if (taken[s[i].second.second.second]) continue;
        int p = i - 1;
        while (p >= 0 && taken[s[p].second.second.second]) p--;
        if (p == -1) continue;
        cout << s[i].second.second.second + 1 << " " << s[p].second.second.second + 1 << endl;
        taken[s[i].second.second.second] = true;
        taken[s[p].second.second.second] = true;
    }
    return 0;
}