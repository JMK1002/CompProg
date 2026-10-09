#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n;
string s;
bool active[100005];
int par[100005];
bool explored[100005];
bool inCycle[100005];
set<int> adj[100005];
set<int> radj[100005];
vector<int> parts;
vector<int> cycle;
int ans = 0;
vector<int> bans;

void clean() {
    for (int i = 0; i <= n; i++) {
        adj[i].clear();
        radj[i].clear();
        explored[i] = false;
        active[i] = false;
        par[i] = 0;
        inCycle[i] = false;
    }
    parts.clear();
    cycle.clear();
    bans.clear();
    ans = 0;
}

void dfs2(int v) {
    for (int i : radj[v]) {
        if (inCycle[i]) continue;
        dfs2(i);
    }
    if (!inCycle[v] && active[v]) {

        active[v] = !active[v];
        active[par[v]] = !active[par[v]];
        ans++;
        bans.push_back(v);
    }
}

void getCycle(int v) {
    int a = v;
    int b = par[v];
    while (a != b) {
        a = par[a];
        b = par[par[b]];
    }
    cycle.push_back(b);
    inCycle[b] = true;
    a = par[a];
    while (a != b) {
        cycle.push_back(a);
        inCycle[a] = true;
        a = par[a];
    }
}

void dfs(int v) {
    explored[v] = true;
    parts.push_back(v);
    for (int i : adj[v]) {
        if (!explored[i]) {
            dfs(i);
        }
    }
    for (int i : radj[v]) {
        if (!explored[i]) {
            dfs(i);
        }
    }
}

void solve() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        active[i] = s[i] == '1';
        cin >> par[i];
        par[i]--;
        adj[i].insert(par[i]);
        radj[par[i]].insert(i);
    }
    for (int i = 0; i < n; i++) {
        if (explored[i]) continue;
        dfs(i);
        getCycle(i);
        for (int j : cycle) {
            dfs2(j);
        }
        int cnt = 0;
        int run = 0;
        vector<int> a;
        vector<int> b;
        for (int j : cycle) {
            cnt += active[j];
            run += cnt % 2;
            if (cnt % 2 == 0) a.push_back(j);
            else b.push_back(j);
        }
        if (cnt % 2 == 1) {
            cout << -1 << endl;
            clean();
            return;
        }
        ans += min(run, (int) cycle.size() - run);
        if (run < (int) cycle.size() - run) for (int j : b) bans.push_back(j);
        else for (int j : a) bans.push_back(j);
        parts.clear();
        cycle.clear();
    }
    cout << ans << endl;
    for (int i : bans) cout << i + 1 << " ";
    cout << endl;
    clean();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}