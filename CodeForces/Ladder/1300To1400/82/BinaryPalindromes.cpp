//
// Created by JMKov on 4/29/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s[n];
        int diffs = 0;
        int palindromes = 0;
        bool a = false;
        for (int i = 0; i < n; i++) {
            cin >> s[i];
            a += a || (s[i].size() % 2 == 1);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < s[i].size() / 2; j++) {
                diffs += s[i][j] != s[i][s[i].size() - j - 1];
            }
        }
        if (a) {
            cout << n << endl;
        }
        else if ((diffs & 1) == 1) {
            cout << n - 1 << endl;
        }
        else {
            cout << n << endl;
        }
    }
    return 0;
}