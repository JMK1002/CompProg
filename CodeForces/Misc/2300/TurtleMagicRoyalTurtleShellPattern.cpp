//
// Created by JMKov on 8/11/2024.
//
#include <iostream>
using namespace std;

int n, m, q;
bool lol[8];

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < 8; i++) lol[i] = true;
    cout << 8 << endl;
    while (q--) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        bool b = s == "circle";

        lol[0] &= ((u % 2) ^ (v % 4 == 0 || v % 4 == 1)) == b;
        lol[1] &= ((!(u % 2)) ^ (v % 4 == 0 || v % 4 == 1)) == b;
        lol[2] &= ((u % 2) ^ (v % 4 == 1 || v % 4 == 2)) == b;
        lol[3] &= ((!(u % 2)) ^ (v % 4 == 1 || v % 4 == 2)) == b;
        swap(u, v);
        lol[4] &= ((u % 2) ^ (v % 4 == 0 || v % 4 == 1)) == b;
        lol[5] &= ((!(u % 2)) ^ (v % 4 == 0 || v % 4 == 1)) == b;
        lol[6] &= ((u % 2) ^ (v % 4 == 1 || v % 4 == 2)) == b;
        lol[7] &= ((!(u % 2)) ^ (v % 4 == 1 || v % 4 == 2)) == b;

        int cnt = 0;
        for (int i = 0; i < 8; i++) cnt += lol[i];
        cout << cnt << endl;
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