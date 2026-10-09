#include<bits/stdc++.h>
#define pc __builtin_popcountll
using namespace std;
typedef long long ll;
const ll _=2e5+5;
ll n,m,q=30,x,t,k,s,a[_],b[16],c[1<<16],i,j;string str;mt19937 rng(time(0));
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>i;
	for(i=0;i<n;i++){cin>>str;for(x=j=0;j<m;j++)x|=ll(str[j]^48)<<j;a[i]=x;}
	while(q--){
		x=rng()%n;t=0;
		for(j=0;j<m;j++)if((a[x]>>j)&1)b[t++]=j;
		for(i=0;i<(1ll<<t);i++)c[i]=0;
		for(i=0;i<n;i++){for(x=j=0;j<t;j++)if((a[i]>>b[j])&1)x|=1ll<<j;c[x]++;}
		for(j=0;j<t;j++)for(i=0;i<(1ll<<t);i++)if((i>>j)&1)c[i^(1ll<<j)]+=c[i];
		for(k=i=0;i<(1ll<<t);i++)if(c[i]>=(n+1)/2&&pc(i)>pc(k))k=i;
		for(x=j=0;j<t;j++)if((k>>j)&1)x|=1ll<<b[j];
		if(pc(x)>pc(s))s=x;
	}
	for(i=0;i<m;i++)cout<<((s>>i)&1);
}
