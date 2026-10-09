//
// Created by JMKov on 6/25/2023.
//
#include <iostream>
#include <set>
#include <queue>
using namespace std;

int cnt[300010];
set<int> connections[300010];

void dfsCount(int node) {
    if (connections[node].empty()) {
        cnt[node] = 1;
        return;
    }
    for (int i : connections[node]) {
        dfsCount(i);
        cnt[node] += cnt[i];
    }
    cnt[node]++;
}

int dfsSolve(int node) {
    if (connections[node].size() == 2) {
//        dp[node] = max(dfsSolve(*connections[node].begin()) + count[(*(++connections[node].begin()))] - 1,
//                       dfsSolve(*(++connections[node].begin())) + count[(*connections[node].begin())] - 1);
        return max(dfsSolve(*connections[node].begin()) + cnt[(*(++connections[node].begin()))] - 1,
                   dfsSolve(*(++connections[node].begin())) + cnt[(*connections[node].begin())] - 1);
    }
    else if (connections[node].size() == 1) {
//        dp[node] = count[*connections[node].begin()] - 1;
        return cnt[*connections[node].begin()] - 1;
    }
    else if (connections[node].empty()) {
//        dp[node] = 0;
        return 0;
    }
//    cout << "SDF" << endl;
    return 0;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            connections[u].insert(v);
            connections[v].insert(u);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : connections[v]) {
                connections[i].erase(v);
                q.push(i);
            }
        }
//        for (int i = 0; i < n; i++) {
//            cout << i << " ";
//            for (int j : connections[i]) cout << j << " ";
//            cout << endl;
//        }
//        cout << endl;
        dfsCount(0);
//        for (int i = 0; i < n; i++) cout << count[i] << " ";
//        cout << endl;
        cout << dfsSolve(0) << endl;
//        cout << n << "SDF" << endl;
//        for (int i = 0; i < n; i++) cout << dp[i] << " ";
//        cout << endl;
        for (int i = 0; i < n; i++) {
            connections[i].clear();
            cnt[i] = 0;
        }

    }
    return 0;
}