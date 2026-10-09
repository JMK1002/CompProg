//
// Created by JMKov on 12/13/2023.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
pair<long long, long long> adj[100003];
set<pair<long long, long long>> radj[100003];
bool explored[100003];

void dfs(int v) {
    if (explored[v]) return;
    explored[v] = true;
    for (pair<long long, long long> e : radj[v]) {
        dfs(e.first);
    }
}

int main() {
    long long ans = 0;
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long u, v;
        cin >> u >> v;
        u--;
        adj[i] = {u, v};
        radj[u].insert({i, v});
        ans += v;
    }

    vector<long long> inds;

    long long ptr = 0;
    while (ptr < n) {
        dfs(ptr);
        int a = ptr;
        int b = adj[ptr].first;
        while (a != b) {
            a = adj[a].first;
            b = adj[adj[b].first].first;
        }
        int mn = b;
        b = adj[b].first;
        while (a != b) {
            if (adj[b].second < adj[mn].second) mn = b;
        }
        ans -= adj[mn].second;
        while (explored[ptr]) ptr++;
    }
    for (int i = 0; i < n; i++) explored[i] = false;

    cout << ans << endl;
    return 0;
}
//7
//5 10
//4 24
//1 39
//2 10
//3 100
//1 40
//6 2