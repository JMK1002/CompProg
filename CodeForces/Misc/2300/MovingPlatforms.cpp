//
// Created by JMKov on 8/11/2024.
//
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const long long INF = 2000000000000000;

long long n, m, h;
long long arr[100005];
long long s[100005];
set<long long> adj[100005];
long long dist[100005];
bool explored[100005];

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if(!b) {x=1, y=0; return a;}
    long long t=exgcd(b,a%b,y,x);
    y-=(a/b)*x; return t;
}

long long nxt(long long t, long long u, long long v)
{
    long long dh=arr[v]+t%h*s[v]-arr[u]-t%h*s[u],dv=s[u]-s[v];
    dh=(dh%h+h)%h, dv=(dv%h+h)%h; long long x,y;
    long long g=exgcd(dv,h,x,y); if(dh%g) return INF;
    long long ans=(dh/g*x%(h/g)+h/g)%(h/g);
    return t+ans;
}
void djikstra(long long start) {
    set<pair<long long, long long>> low;
    for (long long i = 0; i < n; i++) {
        dist[i] = INF;
        explored[i] = false;
        if (i != start) low.insert({dist[i], i});
    }
    low.insert({0, start});
    while (!low.empty()) {
        pair<long long, long long> p = *low.begin();
        low.erase(low.begin());
        explored[p.second] = true;
        dist[p.second] = p.first;
        for (long long e : adj[p.second]) {
            if (explored[e]) continue;
            long long amnt = nxt(p.first, p.second, e) + 1;

            if (amnt < dist[e]) {
                low.erase({dist[e], e});
                dist[e] = amnt;
                low.insert({dist[e], e});
            }
        }
    }
}

void solve() {
    cin >> n >> m >> h;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    for (long long i = 0; i < n; i++) cin >> s[i];
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    djikstra(0);
    if (dist[n - 1] >= INF) cout << -1 << endl;
    else cout << dist[n - 1] << endl;

    for (int i = 0; i <= n; i++) adj[i].clear();
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}