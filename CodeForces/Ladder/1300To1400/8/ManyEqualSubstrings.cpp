//
// Created by JMKov on 4/4/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    int wrapLength = 0;
    // check if I need to have the upper limit as n / 2 + 1
    for (int i = 0; i < n; i++) {
        if (s[i] != s[n - 1]) {
            continue;
        }
        bool works = true;
        for (int j = i; j >= 0; j--) {
            if (s[j] != s[n + j - i - 1]) {
                works = false;
                break;
            }
        }
        if (works && i != n - 1) {
            wrapLength = i + 1;
        }
    }
    string concat = s.substr(wrapLength);
    for (int i = 1; i < k; i++) {
        s += concat;
    }
    cout << s << endl;
    return 0;
}