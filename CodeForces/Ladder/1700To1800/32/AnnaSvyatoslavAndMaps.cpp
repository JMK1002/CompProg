//
// Created by JMKov on 6/18/2023.
//
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int n;
    cin >> n;
    vector<int> connections[n];
    vector<int> pos[n];
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '1') {
                connections[i].push_back(j);
            }
        }
    }
    int m;
    cin >> m;
    int p[m];
    for (int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
        pos[p[i]].push_back(i);
    }
    int table[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) table[i][j] = 0;

    for (int i = 0; i < n; i++) {
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int j : connections[v]) {
                if (j == i || table[i][j] == table[i][v] + 1 || table[i][j] != 0) {
                    continue;
                }
                table[i][j] = table[i][v] + 1;
                q.push(j);
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << table[i][j] << " ";
//        }
//        cout << endl;
//    }

    vector<int> ans;
    ans.push_back(p[0]);
    int position = 0;
    while (position < m - 1) {
        int index = position + 1;
        for (int i = 0; i < n; i++) {
            int v = position + table[p[position]][i];
            if (v < m && p[v] == i) {
                index = max(index, position + table[p[position]][i]);
            }
        }
        position = index;
        ans.push_back(p[index]);
    }

    if (ans[ans.size() - 1] != p[m - 1]) ans.push_back(p[m - 1]);
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << " ";
    cout << endl;
    return 0;
}