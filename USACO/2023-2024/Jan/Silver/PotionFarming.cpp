//
// Created by JMKov on 1/28/2024.
//
#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

set<long long> adj[100004];
set<long long> leafs;
bool hasPot[100004];

int cnt = 0;
int ans = 0;

void dfs(int v, int p) {
    if (hasPot[v]) cnt++;
    if (leafs.find(v) != leafs.end()) {
        ans += (cnt != 0);
        cnt -= (cnt != 0);
    }
    for (long long edge : adj[v]) {
        if (edge == p) continue;
        dfs(edge, v);
    }
    if (hasPot[v] && cnt > 0) cnt--;
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    long long n;
    cin >> n;
    long long p[n];
    for (long long i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    for (long long i = 0; i < n - 1; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for (long long i = 1; i < n; i++) if (adj[i].size() == 1) leafs.insert(i);
//    cout << leafs.size() << endl;

    for (long long i = 0; i < n; i++) hasPot[i] = false;
    for (long long i = 0; i < leafs.size(); i++) hasPot[p[i]] = true;

//    for (long long i = 0; i < n; i++) cout << lst[i] << " ";
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}
//13
//2 3 5 6 10 9 1 4 7 8 11 12 13
//2 1
//3 1
//4 2
//7 4
//2 5
//5 8
//5 9
//2 6
//3 10
//11 10
//10 12
//12 13

//7
//1 3 4 2 5 6 7
//1 2
//2 3
//3 4
//4 5
//4 6
//4 7