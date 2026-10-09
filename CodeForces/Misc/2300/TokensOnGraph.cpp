#include <iostream>
#include <set>
#include <queue>
using namespace std;

long long n, m, p, b; // * p is amnt of tokens and b is amnt of bonuses
set<long long> adj[200005];
bool isToken[200005];
bool isBonus[200005];
bool explored[200005];
long long dist[200005];
long long amnt[200005];
long long cnt = 0;

void dfs(long long v) {
    explored[v] = true;
    cnt++;
    for (long long e : adj[v]) {
        if (explored[e]) continue;
        else if (isBonus[e]) {
            dfs(e);
        }
    }
    long long amntOfTurns = (cnt < 2) ? cnt : 1000000000;
    for (long long e : adj[v]) {
        if (isToken[e]) {
            amnt[e] = max(amntOfTurns, amnt[e]);
        }
    }
}

void bfs() {
    queue<long long> q;
    explored[0] = true;
    q.push(0);
    long long cnt = 0;
    while (!q.empty()) {
        long long sz = q.size();
        for (long long i = 0; i < sz; i++) {
            long long v = q.front();
            q.pop();
            explored[v] = true;
            for (long long e : adj[v]) {
                if (isToken[e]) dist[e] = min(dist[e], cnt);
                if (explored[e] || !isBonus[e]) continue;
                q.push(e);
            }
        }
        cnt++;
    }
}

void solve() {
    cin >> n >> m >> p >> b;
    cnt = 0;
    for (long long i = 0; i <= n; i++) {
        dist[i] = 1000000000000000000;
        isToken[i] = false;
        isBonus[i] = false;
        explored[i] = false;
        amnt[i] = 0;
        adj[i].clear();
    }
    for (long long i = 0; i < p; i++) {
        long long x;
        cin >> x;
        x--;
        isToken[x] = true;
    }
    for (long long i = 0; i < b; i++) {
        long long x;
        cin >> x;
        x--;
        isBonus[x] = true;
    }
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (long long i = 0; i < n; i++) {
        if (explored[i] || !isBonus[i]) continue;
        cnt = 0;
        dfs(i);
    }
    for (long long i = 0; i < n; i++) explored[i] = false;

    bfs();
    long long s = 0;
    for (long long i = 0; i < n; i++) s += amnt[i];
    for (long long j = 0; j < n; j++) {
        if (s - amnt[j] >= dist[j]) {
            cout << "YES" << endl;
            return;
        }
    }
    if (isToken[0]) {
        cout << "YES" << endl;
        return;
    }
    for (int e : adj[0]) {
        if (isToken[e]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}