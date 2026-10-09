#include<bits/stdc++.h>
using namespace std;
#define int long long
const int o=1e5+3;
int n,a,b,s[o],l[o],r[o];
vector<int> g[o];
void dfs(int v,int p){
    for (int i=0;i<g[v].size();i++){
        int x=g[v][i];
        if (x!=p) dfs(x,v),r[v]=max(r[v],r[x]),l[v]=max(l[v],l[x]);
    }
    int x=s[v]+l[v]-r[v];
    if (x<0) l[v]-=x;
    else r[v]+=x;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for (int i=0,x,y;i<n-1;i++)
        cin>>x>>y,x--,y--,g[x].push_back(y),g[y].push_back(x);
    for (int i=0;i<n;i++)
        cin>>s[i];
    dfs(0,-1);
    cout<<l[0]+r[0];
}
//asdf