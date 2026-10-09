//
// Created by JMKov on 12/31/2023.
//
#include <iostream>
#include <queue>
#include <set>

using namespace std;

const long long dirs[4][2] {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
};

long long n, d;
long long arr[1002][1002];
long long maxSize[1002][1002];
bool explored[1002][1002];
set<pair<long long, long long>> exploredCenters[800];

int main() {
    cin >> n >> d;
    queue<pair<pair<long long, long long>, pair<long long, long long>>> exploreQ; // position and then time remaining
    queue<pair<long long, long long>> reverseBFSQ;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '.') arr[i][j] = -1;
            if (c == '#') {
                arr[i][j] = 0;
                reverseBFSQ.push({i, j});
                explored[i][j] = true;
            }
            if (c == 'S') arr[i][j] = -2;

            maxSize[i][j] = arr[i][j];
        }
    }


    while (!reverseBFSQ.empty()) {
        pair<long long, long long> v = reverseBFSQ.front();
        reverseBFSQ.pop();
        for (const long long *dir : dirs) {
            pair<long long, long long> newCoord = {v.first + dir[0], v.second + dir[1]};
            if (newCoord.first < 0 || newCoord.first >= n || newCoord.second < 0 || newCoord.second >= n ||
                explored[newCoord.first][newCoord.second]) {
                continue;
            }
            maxSize[newCoord.first][newCoord.second] = maxSize[v.first][v.second] + 1;
            explored[newCoord.first][newCoord.second] = true;
            reverseBFSQ.push(newCoord);
        }
    }

    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
//            cout << maxSize[i][j] << " ";
        }
//        cout << endl;
    }

    for (long long i = 0; i < n; i++) for (long long j = 0; j < n; j++) {
        explored[i][j] = false;
        if (arr[i][j] == -2) {
            explored[i][j] = true;
            exploreQ.push({{i, j},
                           {d, 1}});
        }
    }
    while (!exploreQ.empty()) {
        pair<pair<long long, long long>, pair<long long, long long>> v = exploreQ.front();
        exploreQ.pop();
        for (const long long *dir : dirs) {
            pair<long long, long long> newCoord = {v.first.first + dir[0], v.first.second + dir[1]};
            if (newCoord.first < 0 || newCoord.first >= n || newCoord.second < 0 || newCoord.second >= n ||
            explored[newCoord.first][newCoord.second] || maxSize[newCoord.first][newCoord.second] < v.second.second) {
                continue;
            }
            long long time = v.second.first - 1;
            long long sz = v.second.second;
            explored[newCoord.first][newCoord.second] = true;
            if (v.second.first == 1 && maxSize[newCoord.first][newCoord.second] <= v.second.second) continue;
            if (v.second.first == 1) {
                time = d;
                sz++;
            }
            exploreQ.push({newCoord, {time, sz}});
        }
    }
//    cout << endl;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            if (explored[i][j]) exploredCenters[maxSize[i][j]].insert({i, j});
//            cout << explored[i][j] << " ";
        }
//        cout << endl;
    }
    for (long long i = 700; i >= 0; i--) {
        for (pair<long long, long long> p : exploredCenters[i]) {
            for (const long long *dir : dirs) {
                pair<long long, long long> nc = {p.first + dir[0], p.second + dir[1]};
                if (i != 1 && !explored[nc.first][nc.second] && arr[nc.first][nc.second] != 0) {
                    exploredCenters[i - 1].insert(nc);
                    explored[nc.first][nc.second] = true;
                }
            }
        }
    }
    long long ans = 0;
//    cout << endl;
    for (long long i = 0; i < n; i++) {
        for (long long j = 0; j < n; j++) {
            ans += explored[i][j];
//            cout << explored[i][j] << " ";
        }
//        cout << endl;
    }
    cout << ans << endl;
    return 0;
}