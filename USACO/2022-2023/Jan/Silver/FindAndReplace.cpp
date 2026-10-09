//
// Created by JMKov on 12/21/2023.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int adj[1000];
vector<int> radj[1000];
set<pair<int, int>> edges;
bool explored[1000];
bool self[1000];
bool hasCycle = false;
int len = 1;

void floyd(int v) {
    hasCycle = false;
    len = 1;

    int a = v;
    int b = adj[a];
    while (a != -1 && b != -1 && a != b) {
        a = adj[a];
        b = adj[adj[b]];
    }

    if (a == -1 || b == -1) {
        hasCycle = false;
        return;
    }
    hasCycle = true;

    b = adj[a];
    while (a != b) {
        b = adj[b];
        len++;
    }
}

int dfs(int v) {
    int ret = 1;
    explored[v] = true;
    if (adj[v] != -1 && !explored[adj[v]]) ret += dfs(adj[v]);
    for (int edge : radj[v]) {
        if (!explored[edge]) ret += dfs(edge);
    }
    return ret;
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length();

    for (int i = 0; i < 1000; i++) {
        adj[i] = -1;
        radj[i].clear();
        explored[i] = false;
        self[i] = false;
    }
    edges.clear();

    bool works = true;
    for (int i = 'A'; i <= 'Z'; i++) works = works && (self[i - 'A'] || (adj[i - 'A'] != -1));
    for (int i = 'a'; i <= 'z'; i++) works = works && (self[i - 'A'] || (adj[i - 'A'] != -1));
    if (works) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) {
            self[s[i] - 'A'] = self[s[i] - 'A'] || (s[i] == t[i]);
            continue;
        }

        if (adj[s[i] - 'A'] != -1 && adj[s[i] - 'A'] != t[i] - 'A') {
            cout << -1 << endl;
            return;
        }

        adj[s[i] - 'A'] = t[i] - 'A';
        radj[t[i] - 'A'].push_back(s[i] - 'A');
        edges.insert({s[i] - 'A', t[i] - 'A'});
    }

    for (int i = 'A'; i <= 'Z'; i++) {
        if (self[i - 'A'] && adj[i - 'A'] != -1) {
            cout << -1 << endl;
            return;
        }
    }

    for (int i = 'a'; i <= 'z'; i++) {
        if (self[i - 'A'] && adj[i - 'A'] != -1) {
            cout << -1 << endl;
            return;
        }
    }

    int ans = edges.size();

    int ptr = 0;
    while (ptr <= ('Z' - 'A') && !explored[ptr]) {
        floyd(ptr);
        int cnt = dfs(ptr);

        if (hasCycle && len == 52) {
            cout << -1 << endl;
            return;
        }
        if (hasCycle && cnt == len) {
            ans += hasCycle;
        }

        while (ptr <= ('Z' - 'A') && explored[ptr]) ptr++;
    }

    ptr = ('a' - 'A');
    while (ptr <= ('z' - 'A') && !explored[ptr]) {
        floyd(ptr);
        int cnt = dfs(ptr);

        if (hasCycle && len == 52) {
            cout << -1 << endl;
            return;
        }

        if (hasCycle && cnt == len) {
            ans += hasCycle;
        }

        while (ptr <= ('z' - 'A') && explored[ptr]) ptr++;
    }

//    for (auto p : edges) cout << p.first << " " << p.second << endl;

    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
//ABCDEFGHIJKL
//BCDABEHIJGHK

//abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXY
//bcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYa

//ABCDEF
//ACDABE

//FwuMHrgoTkDINYlHAnRbrYixDOriobwtbcriiguihxcLAxCRKo
//inlDgiffKbeCEPcgHeIhiPFoeFiFfhnkhGiFFflFIoGCHoAIBf

//52 43