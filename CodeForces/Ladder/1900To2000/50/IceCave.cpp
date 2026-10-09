//
// Created by JMKov on 8/8/2023.
//
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    pair<int, int> start;
    pair<int, int> end;
    cin >> start.first >> start.second;
    cin >> end.first >> end.second;
    start.first--; start.second--;
    end.first--; end.second--;
    int dirs[4][2] = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1}
    };
    int open = 0;
    for (auto dir : dirs) {
        int x = end.first + dir[0];
        int y = end.second + dir[1];
        if (x < 0 || y < 0 || x >= n || y >= m) continue;
        open += (arr[x][y] == '.' || (x == start.first && y == start.second));
    }
    if (start.first == end.first && start.second == end.second) {
        cout << ((open) ? "YES" : "NO") << endl;
        return 0;
    }
    if (arr[end.first][end.second] == '.' && open < 2) {
        cout << "NO" << endl;
        return 0;
    }
    queue<pair<int, int>> q;
    q.push(start);
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for (auto dir : dirs) {
            int x = v.first + dir[0];
            int y = v.second + dir[1];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (x == end.first && y == end.second) {
                cout << "YES" << endl;
                return 0;
            }
            if (arr[x][y] == 'X') continue;
            q.emplace(x, y);
            arr[x][y] = 'X';
        }
    }
    cout << "NO" << endl;
    return 0;
}