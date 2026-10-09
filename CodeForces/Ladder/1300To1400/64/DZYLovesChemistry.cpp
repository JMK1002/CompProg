//
// Created by JMKov on 4/23/2023.
//
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(n, vector<int>(0));
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        connections[x].push_back(y);
        connections[y].push_back(x);
    }
    queue<int> q;
    bool explored[n];
    for (int i = 0; i < n; i++) explored[i] = false;
    int islands = 0;
    int next = 0;
    while (next < n) {
        q.push(next);
        while (!q.empty()) {
            int val = q.front();
            q.pop();
            explored[val] = true;
            for (int i: connections[val]) {
                if (!explored[i]) {
                    q.push(i);
                }
            }
        }
        while (explored[next]) {
            next++;
        }
        islands++;
    }
    cout << (long long) pow( 2, n - islands) << endl;
    return 0;
}