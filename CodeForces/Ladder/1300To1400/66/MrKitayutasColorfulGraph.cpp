//
// Created by JMKov on 4/23/2023.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<vector<int>>> graph(m, vector<vector<int>>(n, vector<int>(0)));
    for (int i = 0; i < m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--; c--;
        graph[c][x].push_back(y);
        graph[c][y].push_back(x);
    }
    int a;
    cin >> a;
    for (int x = 0; x < a; x++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        int ans = 0;
        for (int i = 0; i < m; i++) {
            bool explored[n];
            int color = i;
            queue<int> q;
            q.push(u);
//            cout << "ADF" << endl;
            for (int j = 0; j < n; j++) explored[j] = false;
            while (!q.empty()) {
//                cout << "ASDFSDFSF" << endl;
                int val = q.front();
                q.pop();
                explored[val] = true;
                for (int asdf : graph[color][val]) {
                    if (!explored[asdf]) {
                        q.push(asdf);
                    }
                }
            }
            if (explored[v]) {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}