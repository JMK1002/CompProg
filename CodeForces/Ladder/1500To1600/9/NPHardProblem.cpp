//
// Created by JMKov on 5/7/2023.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> input(m);
    vector<int> connections[n];
    for (int i = 0; i < m; i++) {
        pair<int, int> edge;
        cin >> edge.first >> edge.second;
        edge.first--;
        edge.second--;
        input[i] = edge;
        connections[edge.first].push_back(edge.second);
        connections[edge.second].push_back(edge.first);
    }
    int explored[n];
    for (int i = 0; i < n; i++) explored[i] = -1;
    int depth = 0;
    int ptr = 0;
    queue<int> q;
    vector<int> s1, s2;
    while (ptr < n) {
        q.push(ptr);
        explored[ptr] = depth;
        if (depth & 1) s1.push_back(ptr);
        else s2.push_back(ptr);
        while (!q.empty()) {
            depth++;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                int v = q.front();
//                cout << v << " ";
                q.pop();
                for (int x: connections[v]) {
                    if (explored[x] == -1) {
                        q.push(x);
                        explored[x] = depth;
                        if (depth & 1) s1.push_back(x);
                        else s2.push_back(x);
                    }
                    else if ((explored[x] & 1) ^ (depth & 1)) {
                        cout << -1 << endl;
                        return 0;
                    }
                }
            }
//            cout << endl;
        }
        while (ptr < n && explored[ptr] != -1) ptr++;
    }
    if (s1.empty() || s2.empty()) {
        cout << -1 << endl;
        return 0;
    }
    cout << endl;
    cout << s1.size() << endl;
    for (int i : s1) {
        cout << i + 1 << " ";
    }
    cout << endl;
    cout << s2.size() << endl;
    for (int i : s2) {
        cout << i + 1 << " ";
    }
    return 0;
}