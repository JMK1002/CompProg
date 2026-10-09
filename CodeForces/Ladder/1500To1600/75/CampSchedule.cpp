//
// Created by JMKov on 5/29/2023.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //this code is written by Deviprasad
    const int N = 5e5 + 10;
    int ne[N];
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    s = ' ' + s, t = ' ' + t;
    int a = 0, b = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') a++;
        else b++;
    }
    for (int i = 2, j = 0; i <= m; i++) {
        while (j && t[i] != t[j + 1]) j = ne[j];
        if (t[i] == t[j + 1]) j++;
        ne[i] = j;
    }
    for (int i = 1, j = 1; i <= n; i++) {
        if (t[j] == '1' && a) cout << "1", a--;
        else if (t[j] == '0' && b) cout << "0", b--;
        else if (a) cout << "1", a--;
        else cout << "0", b--;
        if (j == m) j = ne[j];
        j++;
    }
    return 0;
}