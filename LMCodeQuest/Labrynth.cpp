#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y;
        queue<int> q;
        cin >> x >> y;
        string matrix[y];
        int mx, my, tx, ty;
        for (int i = 0; i < y; i++) {
            cin >> matrix[i];
            for (int j = 0; j < x; j++) {
                if (matrix[i][j] == 'T') {
                    tx = j;
                    ty = i;
                }
                if (matrix[i][j] == 'M') {
                    mx = j;
                    my = i;
                }
            }
        }
    }
}