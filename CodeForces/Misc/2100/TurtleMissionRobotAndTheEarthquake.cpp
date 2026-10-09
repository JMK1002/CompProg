//
// Created by JMKov on 6/24/2024.
//
#include <iostream>
#include <queue>
#include <vector>
#include <cstdint>
using namespace std;

int n, m;
bool arr[1004][1004];
bool explored[1004][1004];

void clean() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            arr[i][j] = false;
            explored[i][j] = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    explored[0][0] = true;
    int ans = INT32_MAX;
    int cnt = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            pair<int, int> v = q.front();
            q.pop();

            if (v.second == m - 1) {
                int endY = ((n - 1) + cnt) % n; // dont know if true
                ans = min(ans, cnt + min(abs(v.first - endY), n - abs(v.first - endY)));
                continue;
            }

            if (!(arr[(v.first + n + 1) % n][v.second] || arr[(v.first + n + 2) % n][v.second]) && !explored[(v.first + n + 2) % n][v.second]) {
                q.push({(v.first + n + 2) % n, v.second});
                explored[(v.first + n + 2) % n][v.second] = true;
            }
            if (!arr[(v.first + 1) % n][v.second + 1] && !explored[(v.first + 1) % n][v.second + 1]) {
                q.push({(v.first + 1) % n, v.second + 1});
                explored[(v.first + 1) % n][v.second + 1] = true;
            }
        }
        cnt++;
    }
    cout << ((ans == INT32_MAX) ? -1 : ans) << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}