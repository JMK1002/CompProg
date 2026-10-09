//
// Created by JMKov on 6/27/2023.
//
#include <iostream>
#include <set>
#include <unordered_set>
#include <queue>
using namespace std;

unordered_set<int> connections[200010];
int explored[200010];
int initCount[200010];
int ct[200010];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        connections[u].insert(v);
        connections[v].insert(u);
    }
    int depth = 1;
    int ptr = 0;
    queue<int> q;
    while (ptr < n) {
        q.push(ptr);
        explored[ptr] = depth;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int edge : connections[v]) {
                if (explored[edge] != 0) continue;
                q.push(edge);
                explored[edge] = depth;
            }
        }
        while (ptr < n && explored[ptr] != 0) ptr++;
        depth++;
    }
    for (int i = 0; i < n; i++) {
        ct[explored[i]]++;
        initCount[explored[i]]++;
    }

    int ans = 0;
    int erased = 0;
    set<int> holding;
    for (int i = 0; i < n; i++) {
        ct[explored[i]]--;
        if (erased == holding.size() || holding.find(explored[i]) == holding.end()) {
            ans += erased != holding.size();
            holding.insert(explored[i]);
        }
        if (ct[explored[i]] == 0) {
            erased++;
        }
    }
    cout << ans << endl;
    return 0;
}