//
// Created by JMKov on 7/14/2023.
//
#include <iostream>
#include <set>
#include <map>
using namespace std;

map<int, int> t;

void insert(int v, int val, int bit) {
    if (bit == -1) return;
    else {
        if (val & (1 << bit)) {
            insert(v * 2 + 1, val, bit - 1);
            t[v * 2 + 1]++;
        }
        else {
            insert(v * 2, val, bit - 1);
            t[v * 2]++;
        }
    }
}

void erase(int v, int val, int bit) {
    if (bit == -1) return;
    else {
        if (val & (1 << bit)) {
            erase(v * 2 + 1, val, bit - 1);
            t[v * 2 + 1]--;
        }
        else {
            erase(v * 2, val, bit - 1);
            t[v * 2]--;
        }
    }
}

void query(int v, int val, int bit, int & ans) {
    if (bit == -1) {
        return;
    }
    else {
        int b = val & (1 << bit);
        if (b && (t[v * 2 + 1] == 0) || !b && t[v * 2]) {
            query(v * 2, val, bit - 1, ans);
        }
        else {
            query(v * 2 + 1, val, bit - 1, ans);
            ans |= (1 << bit);
        }
    }
}

int main() {
    int q;
    cin >> q;
    multiset<int> s;
    s.insert(0);
    insert(1, 0, 30);
    while (q--) {
        char c;
        int v;
        cin >> c >> v;
        if (c == '+') {
            s.insert(v);
            insert(1, v, 30);
        } else if (c == '-') {
            s.erase(v);
            erase(1, v, 30);
        } else {
//            cout << ~(v) << endl;
            int asdf = 0;
            query(1, ~(v), 30, asdf);
            cout << (asdf ^ v) << endl;
        }
    }
//    for (int j : s) cout << j << " ";
//    cout << endl;
//    for (pair<int, int> p : t) {
//        cout << p.first << " " << p.second << endl;
//    }
    return 0;
}
//00000
//00001
//00110
//01001
//01011

//11100