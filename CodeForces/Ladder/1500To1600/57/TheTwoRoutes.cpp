//
// Created by JMKov on 5/23/2023.
//
#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool rail = false;
    vector<set<int>> rails(n);
    vector<set<int>> roads(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (a == 0 && b == n - 1 || a == n - 1 && b == 0) {
            rail = true;
        }
        rails[a].insert(b);
        rails[b].insert(a);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rails[i].find(j) == rails[i].end()) {
                roads[i].insert(j);
            }
        }
    }
    int explored[n];
    for (int i = 0; i < n; i++) explored[i] = 0;

    queue<int> q;
    q.push(0);
    explored[0] = 1;

    vector<set<int>> *ptr = &(rail ? roads : rails);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto i : (*ptr)[v]) {
            if (explored[i] == 0) {
                explored[i] = explored[v] + 1;
                q.push(i);
            }
        }
    }
    if (explored[n - 1] == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << explored[n - 1] - 1 << endl;
    return 0;
}