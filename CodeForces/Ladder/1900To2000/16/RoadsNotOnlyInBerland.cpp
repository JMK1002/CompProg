//
// Created by JMKov on 7/25/2023.
//
#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> connections[n];
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        connections[u].insert(v);
        connections[v].insert(u);
    }
    set<pair<int, int>> removable;
    vector<int> starts;
    int explored[n];
    for (int & i : explored) i = -1;
    queue<int> q;
    int pos = 0;
    while (pos < n) {
        q.push(pos);
        starts.push_back(pos);
        explored[pos] = INT32_MAX;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int edge : connections[v]) {
                if (explored[edge] != -1) {
                    if (edge != explored[v]) removable.emplace(min(v, edge), max(v, edge));
                    continue;
                }
                explored[edge] = v;
                q.push(edge);
            }
        }
        while (pos < n && explored[pos] != -1) pos++;
    }
//    for (pair<int, int> p : removable) {
//        cout << p.first << " " << p.second << endl;
//    }
    int cnt = 0;
    cout << removable.size() << endl;
    for (pair<int, int> p : removable) {
        cout << p.first + 1 << " " << p.second + 1 << " " << starts[cnt] + 1 << " " << starts[cnt + 1] + 1 << endl;
        cnt++;
    }
//    cout << starts.size() - 1 << " " << removable.size() << endl;
    return 0;
}