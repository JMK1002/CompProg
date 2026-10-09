#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define eb emplace_back
const int N=1010,M=1e6+10,mod=1e9+7;
int n,m,k,fa[M],siz[M],fg[M],len[M];
struct node{
	int x,y;
}a[M];
inline int gf(int x){
	return fa[x]==x?x:fa[x]=gf(fa[x]);
}
inline void solve(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n*m;++i) fa[i]=i,siz[i]=1,fg[i]=len[i]=0;
	bool ok=1;
	for(int i=1;i<=k+1;++i){
		scanf("%d%d",&a[i].x,&a[i].y);
		if(i>1){
			ok&=(abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)==2);
			if(a[i].x==a[i-1].x||a[i].y==a[i-1].y){
				int x=((a[i].x+a[i-1].x)/2-1)*m+(a[i].y+a[i-1].y)/2;
				x=gf(x);
				fg[x]=1;
				++len[x];
			}
			else{
				int u=(a[i].x-1)*m+a[i-1].y;
				int v=(a[i-1].x-1)*m+a[i].y;
				u=gf(u),v=gf(v);
				if(u!=v){
					fa[u]=v;
					siz[v]+=siz[u];
					len[v]+=len[u]+1;
					fg[v]|=fg[u];
				}
				else fg[u]=2,++len[u];
			}
		}
	}
	if(!ok) return puts("0"),void();
	int ans=1;
	for(int i=1;i<=n*m;++i){
		if(gf(i)==i) ans=1ll*ans*(len[i]<=siz[i]?(fg[i]?fg[i]:siz[i]):0)%mod;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}