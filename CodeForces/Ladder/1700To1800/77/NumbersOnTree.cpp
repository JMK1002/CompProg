//
// Created by JMKov on 7/7/2023.
//
#include<iostream>
#include<vector>
using namespace std;
vector<int> edge[2005];
int c[2005],tag,sz[2005],ans[2005],vis[2005],n,root;
void dfs(int u)
{
    int cnt=-1;sz[u]=1;
    for(int i=1;i<=n;i++)
    {
        cnt+=(!vis[i]);
        if(cnt==c[u])
        {
            ans[u]=i;
            vis[i]=1;
            break;
        }
    }
    for(int i=0;i<edge[u].size();i++)
    {
        int v=edge[u][i];
        dfs(v);
        sz[u]+=sz[v];
    }
    if(sz[u]-1<c[u])
        tag=1;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int u;
        cin>>u>>c[i];
        if(u==0)
            root=i;
        edge[u].push_back(i);
    }
    dfs(root);
    if(tag)
        cout<<"NO\n";
    else
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
    }
}
