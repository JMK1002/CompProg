#include <bits/stdc++.h>

using namespace std;
using ll=long long;
ll n,m;
ll sx,sy;
ll L,R;
bool visited[2002][2002];
ll ans;
char a[2005][2005];
struct node
{
    ll x,y,dl,dr;
};
ll _dx[4]={0,0,1,-1};
ll _dy[4]={1,-1,0,0};
void bfs()
{
    deque<node>q;
    q.push_front({sx,sy,L,R});
    while(q.size())
    {
        node now=q.front();
        q.pop_front();
        ll x=now.x;
        ll y=now.y;
        ll dl=now.dl;
        ll dr=now.dr;
        if(visited[x][y]||dl<0||dr<0||a[x][y]!='.')
            continue;
        ans++;
        visited[x][y]=true;
        q.push_back({x,y-1,dl-1,dr});
        q.push_back({x,y+1,dl,dr-1});
        q.push_front({x+1,y,dl,dr});
        q.push_front({x-1,y,dl,dr});

    }
}
int main()
{
    cin>>n>>m;
    cin>>sx>>sy;
    cin>>L>>R;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
            cin>>a[i][j];
    }
    ans=0;
    bfs();
    cout<<ans;
}
