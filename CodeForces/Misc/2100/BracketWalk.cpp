//
// Created by JMKov on 7/9/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n, q;
string s;
set<int> st;

int main() {
    cin >> n >> q >> s;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && s[i] == ')') st.insert(i);
        if (i % 2 == 1 && s[i] == '(') st.insert(i);
    }
    while (q--) {
        int x;
        cin >> x;
        x--;

        if (n % 2 == 1) {
            cout << "NO" << endl;
            continue;
        }

        if (x % 2 == (s[x] == '(')) st.erase(x);
        else st.insert(x);
        if (s[x] == '(') s[x] = ')';
        else s[x] = '(';
        if (st.empty() || ((*st.begin()) % 2 == 1 && (*--st.end()) % 2 == 0)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}