//
// Created by JMKov on 5/3/2023.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> groups(m);
    vector<vector<int>> table(n);
    vector<int> ans(n);
    vector<bool> explored(n);
    vector<bool> tablesExplored(m);
    for (int i = 0; i < m; i++) {
        tablesExplored[i] = false;
    }
    for (int i = 0; i < n; i++) {
        explored[i] = false;
        ans[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        vector<int> a;
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int b;
            cin >> b;
            b--;
            table[b].push_back(i);
            a.push_back(b);
        }
        groups[i] = a;
    }
    queue<int> q;
    int ptr = 0;
    while (ptr < n) {
        int count = 1;
        q.push(ptr);
        explored[ptr] = true;
        vector<int> visited(1, ptr);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : table[v]) {
                if (tablesExplored[i]) {
                    continue;
                }
                for (int j : groups[i]) {
                    if (!explored[j]) {
                        q.push(j);
                        visited.push_back(j);
                        explored[j] = true;
                        count++;
                    }
                }
                tablesExplored[i] = true;
            }
        }
        for (int i : visited) {
            ans[i] = count;
        }
        while (ptr < n && explored[ptr]) {
            ptr++;
        }
    }
    for (int i : ans) {
        cout << i << " ";
    }
    return 0;
}