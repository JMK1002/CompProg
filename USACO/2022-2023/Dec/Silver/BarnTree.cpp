#include <iostream>
#include <set>
using namespace std;

set<int> adj[200005];
int parent[200005];
int totalBales[200005];
int cnt[200005];
int n;
int leaf = -1;
int sum = 0;
bool explored[200005];

int countBales(int v, int p) {
    parent[v] = p;
    int children = 0;
    for (int edge : adj[v]) {
        if (edge == p) continue;
        children += countBales(edge, v) + 1;
        totalBales[v] += totalBales[edge];
    }
    if (adj[v].size() == 1) leaf = v;
    return children;
}

void dfs(int v) {
    explored[v] = true;
    for (int edge : adj[v]) {
        if (explored[edge]) continue;
        dfs(edge);
    }
    if (sum / n * cnt[v] ) return;
}

int main() {
    cin >> n;
    int bales[n];
    for (int i = 0; i < n; i++) {
        cin >> bales[i];
        sum += bales[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 0; i < n; i++) totalBales[i] = bales[i];

    countBales(0, 0);


    return 0;
}