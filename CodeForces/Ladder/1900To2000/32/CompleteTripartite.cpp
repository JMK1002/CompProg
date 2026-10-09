//
// Created by JMKov on 7/31/2023.
//
#include <iostream>
#include <set>
#include <queue>

using namespace std;

set<int> connections[100010];
int explored[100010];

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
//        u = i / n + 1;
//        v = i % n + 2;
        u--; v--;
        connections[u].insert(v);
        connections[v].insert(u);
    }
    queue<int> q;
    int pos = 0;
    int cnt = 0;
    while (pos < n) {
        cnt++;
        q.push(pos);
        explored[pos] = cnt;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            auto p = connections[v].begin();
            int asdf = 0;
            for (int i = 0; i < n; i++) {
                if (*p == i) {
                    if (asdf < (int) connections[v].size() - 1) {
                        ++p;
                        asdf++;
                    }
                    continue;
                }
                if (explored[i] != 0) continue;
                q.push(i);
                explored[i] = cnt;
            }
            while (pos < n && explored[pos] != 0) pos++;
            if (pos == n) break;
        }
        while (pos < n && explored[pos] != 0) pos++;
    }
//    cout << cnt << endl;
    if (cnt != 3) {
        cout << -1 << endl;
    }
    else {
        for (int i = 0; i < n; i++) cout << explored[i] << " ";
        cout << endl;
    }
    return 0;
}