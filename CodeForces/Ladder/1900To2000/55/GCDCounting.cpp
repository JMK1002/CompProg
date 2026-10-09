#include <bits/stdc++.h>
using namespace std;

const int N = 200043;

vector<int> vs[N];
vector<int> g[N];
vector<int> g2[N];
int a[N];
int used[N];
int d[N];
int n;
int cc = 0;

pair<int, int> bfs(int x, set<int>& used_vertices)
{
    cc++;
    queue<int> q;
    q.push(x);
    d[x] = 1;
    used[x] = cc;
    pair<int, int> ans = make_pair(x, d[x]);
    while(!q.empty())
    {
        int k = q.front();
        used_vertices.insert(k);
        q.pop();
        ans = make_pair(k, d[k]);
        for(auto y : g2[k])
        {
            if(used[y] != cc)
            {
                used[y] = cc;
                d[y] = d[k] + 1;
                q.push(y);
            }
        }
    }
    return ans;
}

int ans = 0;

void upd(int p)
{
    if(vs[p].empty())
        return;
    for(auto x : vs[p])
    {
        g2[x].clear();
        for(auto y : g[x])
            if(a[y] % p == 0)
                g2[x].push_back(y);
    }
    set<int> used_vertices;
    for(auto x : vs[p])
        if(!used_vertices.count(x))
        {
            pair<int, int> z = bfs(x, used_vertices);
            pair<int, int> z2 = bfs(z.first, used_vertices);
            ans = max(ans, z2.second);
        }
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        int x = a[i];
        for(int j = 2; j * 1ll * j <= a[i]; j++)
        {
            if(a[i] % j == 0)
            {
                vs[j].push_back(i);
                while(a[i] % j == 0)
                {
                    a[i] /= j;
                }
            }
        }
        if(a[i] > 1)
        {
            vs[a[i]].push_back(i);
            a[i] = 1;
        }
        a[i] = x;
    }
    for(int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i = 2; i <= 200000; i++)
        upd(i);
    printf("%d\n", ans);
}