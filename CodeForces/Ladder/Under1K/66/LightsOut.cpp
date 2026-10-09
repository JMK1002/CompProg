#include <iostream>
using namespace std;

int main() {
    int dir[5][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0},
        {0, 0}
    };
    bool array[3][3] {
        {true, true, true},
        {true, true, true},
        {true, true, true}
    };
    for (int i = 0; i < 9; i++) {
        int v;
        cin >> v;
        if (v % 2 == 0) {
            continue;
        }
        int x = i % 3;
        int y = i / 3;
        for (int j = 0; j < 5; j++) {
            int* d = dir[j];
            if (x + d[0] < 0 || x + d[0] > 2 || y + d[1] < 0 || y + d[1] > 2) {
                continue;
            }

            array[x + d[0]][y + d[1]] = !array[x + d[0]][y + d[1]];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << array[j][i];
        }
        cout << endl;
    }

    return 0;
}