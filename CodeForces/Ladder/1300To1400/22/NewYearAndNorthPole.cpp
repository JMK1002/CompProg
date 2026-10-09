//
// Created by JMKov on 4/8/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int y = 20000;
    for (int i = 0; i < n; i++) {
        int dist;
        string dir;
        cin >> dist >> dir;
        if ((dir != "South" && y == 20000) || (dir != "North" && y == 0)) {
            cout << "NO" << endl;
            return 0;
        }
        if (dir == "North") {
            y += dist;
        }
        else if (dir == "South") {
            y -= dist;
        }

        if (y > 20000 || y < 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (y != 20000) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}