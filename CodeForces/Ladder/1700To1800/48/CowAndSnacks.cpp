//
// Created by JMKov on 6/26/2023.
//
#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    multiset<int> connections[n];
    int ans = 0;
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
//        if (*(connections[u].lower_bound(v)) == v) {
////            ans++;
//            continue;
//        }
        connections[u].insert(v);
        connections[v].insert(u);
    }

    queue<int> q;
    int ptr = 0;
    bool explored[n];
    for (int i = 0; i < n; i++) explored[i] = false;
    while (ptr < n) {
        q.push(ptr);
        explored[ptr] = true;
        set<int> vert;
        vert.insert(ptr);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int i : connections[v]) {
                if (explored[i]) continue;
                q.push(i);
                explored[i] = true;
                vert.insert(i);
            }
        }
        int edges = 0;
        for (int i : vert) edges += connections[i].size();
        edges /= 2;
        ans += edges - (int) vert.size() + 1;
        while (ptr < n && explored[ptr]) ptr++;
    }
    cout << ans << endl;
    return 0;
}
//9 12
//1 6
//1 4
//2 3
//2 1
//3 4
//6 5
//4 5
//7 8
//8 9
//7 9
//7 2
//9 3

//5 5
//1 2
//1 3
//2 4
//3 4
//2 3