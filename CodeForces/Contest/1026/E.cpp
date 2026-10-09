#include<bits/stdc++.h>
using namespace std;
const int M=4e5+5;
int n,m;
int b[M],cnt[M],vis[M];
array<int,2> e[M];
vector<array<int,2>> d[M];
vector<int> res;
void dfs(int rt,int ee){
//	for(auto [x,y]:d[rt]){
	while(d[rt].size()){
		auto [x,y]=d[rt].back();
		d[rt].pop_back();
		if(vis[y])continue;
		vis[y]=1;
		dfs(x,y);
//		res.push_back(y);
//		break;
	}
	if(ee)res.push_back(ee);
}
void Main(){
	cin>>n;
	int tot=0;
	for(int i=1;i<=2*n;i++)d[i].clear(),vis[i]=0,cnt[i]=0;
	res.clear();
	for(int i=1,x,y;i<=n;i++){
		cin>>x>>y;
		e[i]={x,y+1e9};
		b[++tot]=x;
		b[++tot]=y+1e9;
	}
	sort(b+1,b+tot+1);
	m=unique(b+1,b+tot+1)-b-1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++)e[i][j]=lower_bound(b+1,b+m+1,e[i][j])-b;
//		printf("e1=%d e2=%d\n",e[i][0],e[i][1]);
		d[e[i][0]].push_back({e[i][1],i});
		d[e[i][1]].push_back({e[i][0],i});
		cnt[e[i][0]]++,cnt[e[i][1]]++;
	}
	int o=0,rt=1;
	for(int i=1;i<=2*n;i++)if(cnt[i]%2==1)o++,rt=i;
	if(o!=0&&o!=2){
		puts("NO");
		return;
	}
	dfs(rt,0);
	if(res.size()==n){
		puts("YES");
		for(auto x:res)printf("%d ",x);
		puts("");
	}
	else puts("NO");
}
main(){
	ios::sync_with_stdio(false),cin.tie(0);
	int T=1;
	cin>>T;
	while(T--)Main();
	return 0;
}
