//
// Created by JMKov on 5/15/2023.
//
#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    bool c = false, d = false;
    for (char i : a) {
        if (i == '1') {
            c = true;
            break;
        }
    }
    for (char i : b) {
        if (i == '1') {
            d = true;
            break;
        }
    }
    if (a.size() == b.size() && (c && d || !c && !d)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}