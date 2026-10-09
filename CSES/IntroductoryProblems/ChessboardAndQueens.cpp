//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

bool reserved[8][8];
int cnt;
int explored[8][8];

void place(int x, int y, int amnt) {
    for (int i = 0; i < 8; i++) {
        explored[x][i] += amnt;
        explored[i][y] += amnt;
        if (y - i + x >= 0 && y - i + x < 8) explored[i][y - i + x] += amnt;
        if (y + i - x >= 0 && y + i - x < 8) explored[i][y + i - x] += amnt;
    }
    explored[x][y] -= 3 * amnt;
}

void dfs(int v, int pd) {
    if (v == 64) {
//        for (int i = 0; i < 8; i++) {
//            for (int j = 0; j < 8; j++) {
//                cout << explored[i][j] << " ";
//            }
//            cout << endl;
//        }
        cnt += (pd == 8);
        return;
    }
    int x = v / 8;
    int y = v % 8;
    if (explored[x][y] == 0 && !reserved[x][y]) {
        place(x, y, 1);
        dfs(v + 1, pd + 1);
        place(x, y, -1);
    }
    dfs(v + 1, pd);
}

int main() {
    for (int i = 0; i < 8; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            reserved[i][j] = (s[j] == '*');
        }
    }
    dfs(0, 0);
    cout << cnt << endl;
    return 0;
}