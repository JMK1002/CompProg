#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n; vector<set<int>> adj;
set<int> leafList;

int ask(int u, int v) {
    cout << "? " << u+1 << " " << v+1 << endl; cout.flush();
    int w; cin >> w; assert(w != -1);
    return (w - 1);
}

void answer(int r) {
    cout << "! " << (r+1) << endl;
    cout.flush(); exit(0);
}

void purge(int z, int last, int blockpoint) {
    if (leafList.find(z) != leafList.end()) leafList.erase(z);

    for (int t: adj[z]) {
        if (t == last) continue;
        if (t == blockpoint) adj[t].erase(z);
        else if (adj[t].size() != 0) purge(t, z, blockpoint);
    }

    adj[z].clear();
}

void Input() {
    cin >> n; adj.resize(n);
    for (int i=1; i<n; i++) {
        int x, y; cin >> x >> y; x--; y--;
        adj[x].insert(y); adj[y].insert(x);
    }
}

void Solve() {
    for (int i=0; i<n; i++) {
        if (adj[i].size() == 1) leafList.insert(i);
    }

    while (leafList.size() > 1) {
        int u = *leafList.begin(); leafList.erase(u);
        int v = *leafList.begin(); leafList.erase(v);
        int w = ask(u, v);
        if (w == u || w == v) answer(w);

        purge(u, -1, w); purge(v, -1, w);
        if (adj[w].size() <= 1) leafList.insert(w);
    }

    answer(*leafList.begin());
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(false);
    Input(); Solve(); return 0;
}