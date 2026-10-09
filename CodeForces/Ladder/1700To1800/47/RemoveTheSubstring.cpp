//
// Created by JMKov on 6/26/2023.
//
#include <iostream>
using namespace std;

string s, t;

//bool works(int n) {
//
//}

int main() {
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    int first[m];
    int last[m];
    int ptr = 0;
    for (int i = 0; i < n && ptr < m; i++) {
        if (s[i] == t[ptr]) {
            first[ptr] = i;
            ptr++;
        }
    }
    ptr = m - 1;
    for (int i = n - 1; i >= 0 && ptr >= 0; i--) {
        if (s[i] == t[ptr]) {
            last[ptr] = i;
            ptr--;
        }
    }
//    for (int i : first) cout << i << " ";
//    cout << endl;
//    for (int i : last) cout << i << " ";
//    cout << endl;
    int mx = max(last[0], n - first[m - 1] - 1);
    for (int i = 1; i < m; i++) {
        mx = max(mx, last[i] - first[i - 1] - 1);
    }
    cout << mx << endl;
    return 0;
}