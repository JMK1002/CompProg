#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define N 400000

ll i,j,k,n,m,t,p[N+50],d[N+50],t1;
int in[N+50][2],vis[N+50][2];
basic_string<int> to[N+50][2];

void dfs(int x,int y){
	if(vis[x][y])return;
	//cout<<"nmsl "<<x<<' '<<y<<endl;
	
	vis[x][y]=1; for(auto i:to[x][y])dfs(i,y^1);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<pair<ll,ll> > v,v2;
		for(i=1;i<=n;i++)cin>>p[i];
		for(i=1;i<=n;i++)cin>>d[i];
		for(i=1;i<=n;i++){
			v.push_back({-p[i],i});
			v2.push_back({p[i],i});
		}
		cin>>t1;
		for(i=n+1;i<=n+t1;i++){
			cin>>k; d[i]=0; v.push_back({-k,i});
		}
		for(i=1;i<=n+t1;i++)to[i][0]=to[i][1]={};
		memset(in,0,(n+t1)*8+50);
		memset(vis,0,(n+t1)*8+50);
		sort(v.begin(),v.end()); sort(v2.begin(),v2.end());
		
		map<ll,int> mp;
		for(auto [w,id]:v){
			w=-w; k=(w+m-d[id])%m;
			if(mp.count(k)){
				//cout<<"NMSLA "<<id<<' '<<mp[k]<<endl;
				to[mp[k]][1]+=id,in[id][0]=1;
			}
			if(id<=n)mp[(w+m-d[id])%m]=id;
		}
		
		mp={};
		for(auto [w,id]:v2)if(id<=n){
			k=(w+d[id])%m;
			if(mp.count(k)){
				//cout<<"NMSLB "<<id<<' '<<mp[k]<<endl;
				to[mp[k]][0]+=id,in[id][1]=1;
			}
			if(id<=n)mp[(w+d[id])%m]=id;
		}
		
		for(i=1;i<=n+t1;i++){
			if(!in[i][0])dfs(i,0);
			if(i<=n&&!in[i][1])dfs(i,1);
		}
		
		for(i=n+1;i<=n+t1;i++)cout<<(vis[i][0]?"YES\n":"NO\n");
	}
}