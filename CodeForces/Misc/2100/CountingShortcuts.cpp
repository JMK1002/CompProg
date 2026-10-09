//
// Created by JMKov on 7/24/2024.
//
#include <iostream>
#include <set>
#include <map>

using namespace std;

const int mod = 1000000007;

int n, m, s, t;
int explored[200005];
int amnt[200005];
set<int> adj[200005];
map<int, int> q;

void solve() {
    cin >> n >> m >> s >> t;
    s--; t--;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    q[s] = 1;
    explored[s] = 2;
    int cnt = 0;
    while (!q.empty()) {
        map<int, int> curr = q;
        q.clear();

        if (explored[t] == 2 || (explored[t] && cnt)) {
            break;
        }
        if (explored[t] == 1) cnt++;

        for (pair<int, int> p : curr) {
            explored[p.first]++;
            amnt[p.first] += p.second;
            amnt[p.first] %= mod;
            for (int e : adj[p.first]) {
                if (explored[e] >= 2) continue;
                q[e] += p.second;
                q[e] %= mod;
            }
        }
    }
    cout << amnt[t] % mod << endl;

    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        amnt[i] = 0;
        explored[i] = 0;
    }
    q.clear();
}

int main() {
    int _;
    cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}