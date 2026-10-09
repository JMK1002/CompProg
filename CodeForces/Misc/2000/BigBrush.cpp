//
// Created by JMKov on 6/16/2024.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
int arr[1002][1002];
int ogArr[1002][1002];
int check[1002][1002];
bool explored[1002][1002];
queue<pair<int, int>> q;
vector<pair<pair<int, int>, int>> ans;

int getCol(pair<int, int> p) {
    int i = p.first; int j = p.second;

    int v = arr[i][j];
    if (v == -1) v = arr[i + 1][j];
    if (v == -1) v = arr[i][j + 1];
    if (v == -1) v = arr[i + 1][j + 1];

    return v;
}

void add(pair<int, int> p) {
    int i = p.first; int j = p.second;
    for (int l = -1; l <= 1; l++) {
        for (int k = -1; k <= 1; k++) {
            q.push({i + l, j + k});
        }
    }
}

void clear(pair<int, int> p) {
    int i = p.first; int j = p.second;
    arr[i][j] = -1;
    arr[i + 1][j] = -1;
    arr[i][j + 1] = -1;
    arr[i + 1][j + 1] = -1;
}

bool valid(pair<int, int> p) {
    int i = p.first; int j = p.second;

    int v = getCol(p);

    bool works = true;
    works &= (v == arr[i][j] || arr[i][j] == -1);
    works &= (v == arr[i + 1][j] || arr[i + 1][j] == -1);
    works &= (v == arr[i][j + 1] || arr[i][j + 1] == -1);
    works &= (v == arr[i + 1][j + 1] || arr[i + 1][j + 1] == -1);

    return works;
}

bool checkWorks() {
    for (pair<pair<int, int>, int> p : ans) {
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                check[p.first.first + i][p.first.second + j] = p.second;
            }
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (ogArr[i][j] != check[i][j]) return false;
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ogArr[i][j];
            arr[i][j] = ogArr[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (valid({i, j})) {
                q.push({i, j});
            }
        }
    }

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        if (p.first < 0 || p.second < 0 || p.first >= n - 1 || p.second >= m - 1 || explored[p.first][p.second] || !valid(p) || getCol(p) == -1) continue;
        explored[p.first][p.second] = true;
        ans.push_back({p, getCol(p)});
        clear(p);
        add(p);
    }
    reverse(ans.begin(), ans.end());

    if (!checkWorks()) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (pair<pair<int, int>, int> p: ans) {
        cout << p.first.first + 1 << " " << p.first.second + 1 << " " << p.second << endl;
    }
    return 0;
}