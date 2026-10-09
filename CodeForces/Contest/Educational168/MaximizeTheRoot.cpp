//
// Created by JMKov on 7/30/2024.
//
#include <iostream>
#include <set>

using namespace std;

int n;
int arr[200005];
set<int> adj[200005];

int dfs(int v, int p) {
    if (adj[v].size() == 1) return arr[v];

    int mn = INT_MAX;
    for (int e : adj[v]) {
        if (e == p) continue;
        mn = min(mn, dfs(e, v));
    }
    if (arr[v] > mn) return mn;
    return (arr[v] + mn) / 2;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[i].insert(p);
        adj[p].insert(i);
    }
    int mn = INT_MAX;
    for (int e : adj[0]) {
        mn = min(mn, dfs(e, 0));
    }
    cout << arr[0] + mn << endl;

    for (int i = 0; i <= n; i++) {
        arr[i] = 0;
        adj[i].clear();
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}