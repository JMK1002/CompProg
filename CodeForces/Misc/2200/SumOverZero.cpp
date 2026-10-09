// LUOGU_RID: 112872288
#include<bits/stdc++.h>
using namespace std;
#define N 200010
#define LL long long
int n,m,f[N],t[N];
LL s[N];
map<LL,int>mp;
int lowbit(int x){return x&(-x);}
void cg(int x,int c){while(x<N)t[x]=max(t[x],c),x+=lowbit(x);}
int ask(int x){int r=-1e9;while(x)r=max(r,t[x]),x-=lowbit(x);return r;}
int main()
{
	mp[0]=1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
		s[i]+=s[i-1];
		mp[s[i]]=1;
	}
	for(auto pi:mp)mp[pi.first]=++m;
	for(int i=0;i<N;i++)t[i]=-1e9;
	cg(mp[0],0);
	for(int i=1;i<=n;i++){
		f[i]=max(f[i],f[i-1]);
		f[i]=max(f[i],ask(mp[s[i]])+i);
		cg(mp[s[i]],f[i]-i);
	}
	printf("%d\n",f[n]);
}