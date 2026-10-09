#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll _=2e5+5,K=1e6;
ll N,n,m,k,x,y,u,v,a[_*3],b[_*3],c[_],d[_],i,j;vector<ll>E[_];
inline void p(ll x){for(ll y:E[x])if(!b[y])b[y]=b[x]%k+1,p(y);}
inline void P(){
	cin>>n>>k;u=v=a[0]=b[0]=c[0]=d[0]=0;E[0].clear();
	for(i=1;i<=n;i++)cin>>a[i],u+=a[i],b[i]=c[i]=0,E[i].clear();
	cin>>m;
	for(i=0;i<m;i++)cin>>x>>y,E[x].emplace_back(y);
	b[1]=1;p(1);
	for(i=1;i<=n;i++)c[b[i]%k]+=(a[i]?K:1);
	for(i=1;i<=n;i++)cin>>a[i],v+=a[i],b[i]=d[i]=0,E[i].clear();
	cin>>m;
	for(i=0;i<m;i++)cin>>x>>y,E[x].emplace_back(y);
	b[1]=1;p(1);
	for(i=1;i<=n;i++)a[i]?++d[(b[i]+1)%k]:(d[(b[i]+k-1)%k]+=K);
	if(u+v!=n){cout<<"NO\n";return;}
	if(u==0||v==0){cout<<"YES\n";return;}
	for(i=0;i<k;i++)a[i]=c[i],a[k+1+i]=a[k*2+1+i]=d[i];
	a[k]=a[k*3+1]=-1;b[0]=0;
	for(i=1;i<=k*3;i++){
		for(j=b[i-1];j>0&&a[i]!=a[j];j=b[j-1]);
		b[i]=j+(a[i]==a[j]);
	}
	for(i=k*2;i<=k*3;i++)if(b[i]==k){cout<<"YES\n";return;}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;while(N--)P();
}