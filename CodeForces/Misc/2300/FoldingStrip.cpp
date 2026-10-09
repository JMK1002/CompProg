//
// Created by JMKov on 8/7/2024.
//
#include <iostream>
using namespace std;

int n;
string s;

void solve() {
    cin >> n >> s;
    int cnt = 0;
    int l = 0;
    int r = 0;
    int pos = -1;
    bool dir = true;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i - cnt]) cnt++;
        else {
            if (dir) pos++;
            else pos--;
            r = max(r, pos);
            l = min(l, pos);
            dir = (cnt % 2 == 1) == dir;
            cnt = 1;
        }
    }
    if (dir) pos++;
    else pos--;
    r = max(r, pos);
    l = min(l, pos);
    cout << r - l + 1 << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}