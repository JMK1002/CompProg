//
// Created by JMKov on 3/21/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '9' & i == 0) {
            continue;
        }
        if (s[i] - '4' > 0) {
            s[i] = ('9' - s[i] + '0');
        }
    }
    cout << s << endl;
    return 0;
}