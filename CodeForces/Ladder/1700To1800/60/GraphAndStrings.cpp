//
// Created by JMKov on 6/30/2023.
//
#include <iostream>
#include <set>
#include <queue>
using namespace std;

bool connected[501][501];
bool aOrC[501];

int main() {
    int n, m;
    cin >> n >> m;
    set<int> connections[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        connected[u][v] = true;
        connected[v][u] = true;
        connections[u].insert(v);
        connections[v].insert(u);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!connected[i][j]) {
                aOrC[i] = true;
                aOrC[j] = true;
            }
        }
    }
    string ans;
    for (int i = 0; i < n; i++) ans += "c";
    for (int i = 0; i < n; i++) if (!aOrC[i]) ans[i] = 'b';
    bool explored[n];
    for (int i = 0; i < n; i++) explored[i] = false;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (aOrC[i]) {
            q.push(i);
            ans[i] = 'a';
            explored[i] = true;
            break;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int edge : connections[v]) {
            if (!aOrC[edge] || explored[edge]) continue;
            q.push(edge);
            explored[edge] = true;
            ans[edge] = 'a';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((ans[i] == ans[j] || (ans[i] == 'b' || ans[j] == 'b')) && !connected[i][j]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    cout << ans << endl;
    return 0;
}