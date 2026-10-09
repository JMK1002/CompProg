//
// Created by JMKov on 8/21/2023.
//
#include <iostream>
#include <set>
using namespace std;

int cnt[3002][3002];
bool explored[3002][3002];
int ans = 0;
const int dirs[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
};

void visit(int x, int y) {
    if (x >= 3000 || x < 0 || y >= 3000 || y < 0 || explored[x][y]) return;
//    cout << "SDF" << endl;
    explored[x][y] = true;
    ans++;
    if (cnt[x][y] == 3 && explored[x][y]) {
        for (auto dir2: dirs) {
            visit(x + dir2[0], y + dir2[1]);
        }
    }
    for (auto dir : dirs) {
        int nx = dir[0] + x;
        int ny = dir[1] + y;
        if (nx >= 3000 || nx < 0 || ny >= 3000 || ny < 0) continue;
        cnt[nx][ny]++;
        if (cnt[nx][ny] == 3 && explored[nx][ny]) {
            for (auto dir2: dirs) {
                visit(nx + dir2[0], ny + dir2[1]);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x += 1500;
        y += 1500;
        visit(x, y);
        cout << ans - i - 1 << endl;
    }
//    for (int i = -1; i < 10; i++) {
//        for (int j = -1; j < 10; j++) {
//            cout << explored[i + 1500][j + 1500] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}