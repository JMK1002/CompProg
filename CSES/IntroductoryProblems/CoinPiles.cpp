//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (((x % 3 == 0 && y % 3 == 0) ||
                (x % 3 == 1 && y % 3 == 2) ||
                (x % 3 == 2 && y % 3 == 1)) &&
                min(x, y) * 2 >= max(x, y)) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}