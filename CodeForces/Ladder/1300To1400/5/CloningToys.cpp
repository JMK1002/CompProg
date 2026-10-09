//
// Created by JMKov on 4/3/2023.
//
#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x == 0 && y == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    if (y < 2) {
        cout << "No" << endl;
        return 0;
    }
    y--;
    x -= y;
    if (x < 0 || x % 2 == 1) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}