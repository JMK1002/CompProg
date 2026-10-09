//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

string s;
int n;

set<string> ans;

int perm[8];
bool explored[8];

void gen(int ind) {
    if (ind == n) {
        string ns;
        for (int i = 0; i < n; i++) {
            ns += s[perm[i]];
        }
        ans.insert(ns);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (explored[i]) continue;
        perm[ind] = i;
        explored[i] = true;
        gen(ind + 1);
        explored[i] = false;
    }
}

int main() {
    cin >> s;
    n = s.length();
    sort(s.begin(), s.end());
    gen(0);
    cout << ans.size() << endl;
    for (string a : ans) {
        cout << a << endl;
    }
    return 0;
}