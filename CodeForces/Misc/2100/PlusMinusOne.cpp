//
// Created by JMKov on 6/21/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[504][3];
set<int> adj[1008];
set<int> radj[1008];
bool explored[1008];
int scc[1008];
int cnt = 1;
vector<int> ord;

void addEdges(int a, int b, int c) {
    int aInd = (a < 0) ? a * -1 - 1 : a + n - 1;
    int bInd = (b < 0) ? b * -1 + n - 1 : b - 1;
    int cInd = (c < 0) ? c * -1 + n - 1 : c - 1;
    if (aInd != bInd) { // dont know if necessary if statement
        adj[aInd].insert(bInd);
        radj[bInd].insert(aInd);
    }
    if (aInd != cInd) {
        adj[aInd].insert(cInd);
        radj[cInd].insert(aInd);
    }
}

void dfs1(int v) {
    explored[v] = true;
    for (int e : adj[v]) {
        if (explored[e]) continue;
        dfs1(e);
    }
    ord.push_back(v);
}

void dfs2(int v) {
    scc[v] = cnt;
    for (int e : radj[v]) {
        if (scc[e] != 0) continue;
        dfs2(e);
    }
}

void kosaraju() {
    for (int i = 0; i < 2 * n; i++) {
        if (!explored[i]) dfs1(i);
    }
    reverse(ord.begin(), ord.end());

    for (int i : ord) {
        if (scc[i] == 0) {
            dfs2(i);
            cnt++;
        }
    }
}

bool works() {
    for (int i = 0; i < n; i++) {
        if (scc[i] == scc[i + n]) return false;
    }
    return true;
}

void clean() {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 3; j++) arr[i][j] = 0;
    }
    for (int i = 0; i <= 2 * n; i++) {
        adj[i].clear();
        radj[i].clear();
        explored[i] = false;
        scc[i] = 0;
    }
    cnt = 1;
    ord.clear();
}

void solve() {
    cin >> n;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[j][i];
        }
    }
    for (int i = 0; i < n; i++) {
        addEdges(arr[i][0], arr[i][1], arr[i][2]);
        addEdges(arr[i][1], arr[i][0], arr[i][2]);
        addEdges(arr[i][2], arr[i][1], arr[i][0]);
    }

    kosaraju();
//    for (int i = 0; i < 2 * n; i++) {
//        for (int j : adj[i]) cout << i << " " << j << endl;
//        cout << endl;
//    }
    bool ans = works();

    cout << (ans ? "YES" : "NO") << endl;
    clean();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
// 1 2 3 4 5
// 1 1 1