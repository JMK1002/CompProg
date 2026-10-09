//
// Created by JMKov on 5/16/2023.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (((s[i] - '0') * 4 + (s[j] - '0') * 2 + s[k] - '0') % 8 == 0) {
                    cout << "YES" << endl << (s[i] - '0') * 100 + (s[j] - '0') * 10 + s[k] - '0' << endl;
                    return 0;
                }
            }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int k = j + 1; k < n; k++) {
            if (((s[j] - '0') * 2 + s[k] - '0') % 8 == 0) {
                cout << "YES" << endl << (s[j] - '0') * 10 + s[k] - '0' << endl;
                return 0;
            }
        }
    }
    for (int k = 0; k < n; k++) {
        if ((s[k] - '0') % 8 == 0) {
            cout << "YES" << endl << s[k] - '0' << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}