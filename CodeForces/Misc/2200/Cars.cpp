#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector< pair<int,int> >p[N];
vector<int> g[N];
int col[N]={0},d[N],vis[N]={0},ans[N],pos[N];
bool dfs(int x,int color){
	col[x]=color;
	bool ok=1;
	for(auto i:p[x]){
		if(col[i.first]==-1)ok=dfs(i.first,1-color);
		else if(col[i.first]!=1-color){
			ok=0;
		}
		if(!ok)break;
		if(col[x]==i.second)g[x].push_back(i.first),d[i.first]++;
		else g[i.first].push_back(x),d[x]++;
	}return ok;
}

int main(){
	int n,m,ty,u,v,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)col[i]=-1;
	while(m--){
		cin>>ty>>u>>v;
		p[u].push_back({v,ty-1});
		p[v].push_back({u,ty-1});
	}
	bool ok=1;
	for(int i=1;i<=n&&ok;i++)if(col[i]==-1){
		ok=dfs(i,1);
	}
	if(!ok){
		cout<<"NO";
		return 0;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)if(!d[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ans[++cnt]=x;
		for(auto i:g[x]){
			d[i]--;
			if(!d[i])q.push(i);
		}
	}
	if(cnt!=n){
		cout<<"NO";
		return 0;
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)pos[ans[i]]=i;
	for(int i=1;i<=n;i++)cout<<(col[i]?"R":"L")<<" "<<pos[i]<<"\n";
	return 0;
}