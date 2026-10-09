//
// Created by JMKov on 7/23/2023.
//
#include <iostream>
#include <set>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;

set<int> connections[100010];

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        connections[u].insert(v);
        connections[v].insert(u);
    }
    vector<int> unexplored(n);
    iota(unexplored.begin(), unexplored.end(), 0);
    bool explored[n];
    for (bool & i : explored) i = false;
    queue<int> q;
    int count = 0;
    while (!unexplored.empty()) {
        q.push(*unexplored.begin());
        unexplored.erase(unexplored.begin());
        count++;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i = 0; i < unexplored.size(); i++) {
                if (connections[v].count(unexplored[i]) != 0) continue;
                q.push(unexplored[i]);
                unexplored.erase(unexplored.begin() + i);
                i--;
            }
        }
//        for (bool i : explored) cout << i << " ";
//        cout << endl;
    }
    cout << count - 1 << endl;
    return 0;
}