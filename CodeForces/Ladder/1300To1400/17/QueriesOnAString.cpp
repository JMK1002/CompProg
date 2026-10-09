//
// Created by JMKov on 4/7/2023.
//
#include <iostream>
#include <string>
using namespace std;

string query (string s, int l, int r, int k);

int main() {
    string s;
    int q;
    cin >> s >> q;
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        s = query(s, l, r, k);
    }
    cout << s << endl;
    return 0;
}

string query (string s, int l, int r, int k) {
    string out = s;
    int rangeLength = r - l + 1;
    k %= rangeLength;
    for (int i = 0; i < rangeLength; i++) {
        out[(i + k) % rangeLength + l] = s[i + l];
    }
    return out;
}