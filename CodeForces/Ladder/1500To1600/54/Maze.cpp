//
// Created by JMKov on 5/22/2023.
//
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dirs[4][2] = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int depth[n][m];
    pair<int, int> start;
    vector<vector<pair<int, int>>> depthHashTable;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#') {
                depth[i][j] = -1;
            }
            else {
                depth[i][j] = 0;
                start.first = i;
                start.second = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push(start);
    depth[start.first][start.second] = 1;
    int mx = 0;
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        for (auto dir : dirs) {
            int x = cell.first + dir[0];
            int y = cell.second + dir[1];
            if (x < 0 || x >= n || y < 0 || y >= m || depth[x][y] != 0) {
                continue;
            }
            int newDepth = depth[cell.first][cell.second] + 1;
            depth[x][y] = newDepth;
            while (depthHashTable.size() <= newDepth) depthHashTable.emplace_back(0);
            mx = max(mx, newDepth);
            depthHashTable[newDepth].emplace_back(x, y);
            q.emplace(x, y);
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout << depth[i][j] << " ";
//        }
//        cout << endl;
//    }
    int v;
    int count = 0;
    for (v = mx; v > 0 && count < k; v--) {
        for (auto & j : depthHashTable[v]) {
            arr[j.first][j.second] = 'X';
            count++;
            if (count == k) {
                break;
            }
        }
    }
    for (string s : arr) {
        cout << s << endl;
    }
    return 0;
}