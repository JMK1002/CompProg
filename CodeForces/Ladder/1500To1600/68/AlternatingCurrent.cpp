//
// Created by JMKov on 5/26/2023.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; (i >= 0 && i + 1 < s.size()); i++) {
        while (i >= 0 && i + 1 < s.size() && s[i] == s[i + 1]) {
            s.erase(s.begin() + i);
            s.erase(s.begin() + i);
            i--;
        }
    }
    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
