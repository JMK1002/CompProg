#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
#define f first
#define s second

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e5 + 69;
int n, m, k;
vector <int> adj[N];
int path[N], deg[N], d[N];


void Solve()
{
    cin>>n>>m;
    for (int i=1; i<=m; i++){
        int u, v; cin>>u>>v;
        adj[v].push_back(u);
        //  adj[v].push_back(u);
    }

    for (int i=1; i<=n; i++)
        d[i] = INF;

    cin>>k;
    for (int i=1; i<=k; i++)
        cin>>path[i];

    //bfs from path[k]
    //build dag
    //count number of paths
    queue <int> q;
    q.push(path[k]);
    d[path[k]] = 0;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v: adj[u]){
            if (d[v] > d[u] + 1){
                d[v] = d[u] + 1;
                q.push(v);
                deg[v]++;
            } else if (d[v] == d[u] + 1){
                deg[v]++;
            }
        }
    }

    // for (int i=1; i<=n; i++){
    //     cout<<d[i]<<" ";
    // }
    // cout<<"\n";

    int ans1 = 0, ans2 = 0;

    for (int i=1; i<k-1; i++){
        //does this path reduce the answer
        if (d[path[i]] <= d[path[i + 1]]) ans2++, ans1++;
        else if (deg[path[i]] != 1)ans2++;
    }

    cout<<ans1<<" "<<ans2<<"\n";
}

int main()
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //   cin >> t;
    for(int i = 1; i <= t; i++)
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}