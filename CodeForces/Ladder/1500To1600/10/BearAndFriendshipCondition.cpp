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
    vector<int> connections[n];
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }
    bool explored[n];
    for (int i = 0; i < n; i++) explored[i] = false;
    queue<int> q;
    int ptr = 0;
    while (ptr < n) {
        q.push(ptr);
        explored[ptr] = true;
        int islandSize = 1;
        int prevSize = connections[ptr].size();
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : connections[v]) {
                if (prevSize != connections[i].size() && !explored[i]) {
//                    cout << i << " " << connections[i].size() << endl;
                    cout << "NO" << endl;
                    return 0;
                }
                else if (!explored[i]) {
                    q.push(i);
                    explored[i] = true;
                    islandSize++;
                }
            }
        }
        if (prevSize != islandSize - 1) {
//            cout << islandSize << endl;
            cout << "NO" << endl;
            return 0;
        }
        while (explored[ptr]) ptr++;
//        for (bool i : explored) {
//            cout << i << " ";
//        }
//        cout << endl;
    }
    cout << "YES" << endl;
    return 0;
}