//
// Created by JMKov on 6/14/2024.
//
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n;
set<int> adj[200005];
pair<int, int> dp[200005][2];
int ans[200005];

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    return {a.first + b.first, a.second + b.second};
}

bool comp(int v) {
    pair<int, int> a = dp[v][0];
    pair<int, int> b = dp[v][1];
    if (a.first != b.first) return (a < b);
    else return (a > b);
}

void dfs(int v, int p) {
    dp[v][1] = {1, adj[v].size()};
    dp[v][0] = {0, 1};
    for (int e : adj[v]) {
        if (e == p) continue;
        dfs(e, v);
        dp[v][0] = add(dp[v][0], dp[e][comp(e)]);
        dp[v][1] = add(dp[v][1], dp[e][0]);
    }
}

void dfs2(int v, int p, int l) {
    int next = 0;
    if (l == 0) {
        if (comp(v)) {
            ans[v] = adj[v].size();
            next = 1;
        }
        else {
            ans[v] = 1;
        }
    }
    else ans[v] = 1;
    for (int e : adj[v]) {
        if (e == p) continue;
        dfs2(e, v, next);
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    if (n == 2) {
        cout << "2 2\n1 1" << endl;
        return;
    }

//    int ind = 0;
//    for (int i = 0; i < n; i++) {
//        if (adj[i].size() == 1) continue;
//        dfs(i, 200002);
//        ind = i;
//        break;
//    }
    dfs(0, 200004);
    dfs2(0, 200004, 0);

    pair<int, int> p = dp[0][comp(0)];

    cout << p.first << " " << p.second << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}

int main() {
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//11
//1 2
//2 3
//2 4
//4 5
//4 6
//4 7
//4 8
//4 9
//9 10
//9 11