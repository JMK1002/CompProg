//
// Created by JMKov on 8/4/2023.
//
#include <iostream>
using namespace std;

pair<pair<int, int>, pair<int, int>> rest;

bool valid(int i, int j, int k) {
    pair<int, int> asdf[3];
    asdf[0] = {i, j};
    asdf[1] = {j, k};
    asdf[2] = {k, i};
    for (int m = 0; m < 3; m++) {
        if (asdf[m] == rest.first || asdf[m] == rest.second) {
            return false;
        }
    }
    return true;
}

bool shortValid(int i, int j, int k) {
    pair<int, int> asdf[2];
    asdf[0] = {i, j};
    asdf[1] = {j, k};
    for (int m = 0; m < 2; m++) {
        if (asdf[m] == rest.first || asdf[m] == rest.second) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    rest.first = {s[0] - 'a', s[1] - 'a'};
    rest.second = {t[0] - 'a', t[1] - 'a'};
    string ans;
    string pat;
    bool asdf = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            if (valid(i, j, 3 - i - j)) {
                pat = "";
                pat += (char) (i + 'a');
                pat += (char) (j + 'a');
                pat += (char) (3 - j - i + 'a');
                asdf = true;
                break;
            }
            if (shortValid(i, j, 3 - i - j)) {
                pat = "";
                pat += (char) (i + 'a');
                pat += (char) (j + 'a');
                pat += (char) (3 - j - i + 'a');
                break;
            }
        }
        if (asdf) break;
    }
//    int cnt = 30;
//    while (cnt >= 0) {
//        ans += ans;
//        if (n & (1 << cnt)) {
//            ans += pat;
//        }
//        cnt--;
//    }
    if (rest.first.first != rest.first.second && rest.second.first != rest.second.second) {
        for (int i = 0; i < n; i++) ans += pat[0];
        for (int i = 0; i < n; i++) ans += pat[1];
        for (int i = 0; i < n; i++) ans += pat[2];
    }
    else {
        for (int i = 0; i < n; i++) ans += pat;
    }
    cout << "YES" << endl;
//    cout << pat << endl;
    cout << ans << endl;
    return 0;
}
//abc
//acb
// ab, bc, ca
// ba, cb, ac