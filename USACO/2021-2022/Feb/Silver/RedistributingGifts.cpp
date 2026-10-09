//
// Created by JMKov on 12/11/2023.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> better[502];
vector<int> order[502];
set<int> group[502];
bool adj[502][502];
bool revAdj[502][502];
bool explored1[502];
bool explored2[502];
int parent[502];
int n;

int rt(int a) {
    if (parent[a] == a) return a;
    int ret = rt(parent[a]);
    parent[a] = ret;
    return ret;
}

bool connected(int a, int b) {
    int pa = rt(a);
    int pb = rt(b);

    return (pa == pb);
}

void connect(int a, int b) {
    if (connected(a, b)) return;
    parent[rt(a)] = rt(b);
}


// normal forwards dfs;
void dfs1(int v) {
    explored1[v] = true;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !explored1[i]) dfs1(i);
    }
}

// normal forwards dfs;
void dfs2(int v) {
    explored2[v] = true;
    for (int i = 0; i < n; i++) {
        if (revAdj[v][i] && !explored2[i]) dfs2(i);
    }
}

void kosaraju() {
    for (int i = 0; i < n; i++) parent[i] = i;

    int ptr = 0;
    set<int> explored;
    while (ptr < n) {
        for (int i = 0; i < n; i++) {
            explored1[i] = false;
            explored2[i] = false;
        }
        explored.insert(ptr);
        dfs1(ptr);
        dfs2(ptr);

        for (int i = 0; i < n; i++) if (explored2[i] && explored1[i] && (explored.find(i) == explored.end())) {
            connect(i, ptr);
            explored.insert(i);
        }

        while (ptr < n && explored1[ptr] && explored2[ptr]) ptr++;
    }
}

void solve() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            x--;
            if (x == i) found = true;

            if (!found) {
                better[i].insert(x);
                order[i].push_back(x);
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j : better[i]) cout << j << " ";
//        cout << endl;
//    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = (bool) (better[i].find(j) != better[i].end());
            revAdj[j][i] = adj[i][j];
        }
    }

    kosaraju();
//    for (int i = 0; i < n; i++) cout << parent[i] << " ";
//    cout << endl;

    for (int i = 0; i < n; i++) {
        group[rt(i)].insert(i);
    }

    for (int i = 0; i < n; i++) {
        auto e = group[parent[i]].end();
        int ans = i;
        for (int j : order[i]) {
            if (group[parent[i]].find(j) != e) {
                ans = j;
                break;
            }
        }
        cout << ans + 1 << endl;
    }
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie();


    solve();
    return 0;
}