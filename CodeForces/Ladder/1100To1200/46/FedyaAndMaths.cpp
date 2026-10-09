//
// Created by JMKov on 3/22/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int array[4][4] = {
            1, 1, 1, 1,
            2, 4, 3, 1,
            3, 4, 2, 1,
            4, 1, 4, 1
    };

    int a;
    if (s.size() == 1) {
        a = (s[s.size() - 1] - '0');
    } else {
        a = (s[s.size() - 2] - '0') * 10 + (s[s.size() - 1] - '0');
    }
    if (a == 0) {
        cout << 4 << endl;
        return 0;
    }
    cout << (a % 4 == 0) * 4 << endl;
    return 0;
}