//
// Created by JMKov on 4/21/2023.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool grid[4][4];
    int vVals[2][2] {
            {3, 1},
            {1, 1}
    };
    int hVals[2][2] {
            {1, 3},
            {1, 1}
    };

    bool v = false;
    bool h = false;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '0') {
            cout << vVals[v][0] << " " << vVals[v][1] << endl;
            v = !v;
        }
        else {
            cout << hVals[h][0] << " " << hVals[h][1] << endl;
            h = !h;
        }
    }
    return 0;
}