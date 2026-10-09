#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10,M=33;
int T,n,Q,a[N];
ll f[M],sum;
int t[M];
void solve(int x)
{
	const int k=(1<<x)-1;
	pair<int,int> res={0x3f3f3f3f,-1};
	for(int i=1;i<=n;i++)
	{
		int w=k+1-(a[i]&k);
		res=min(res,{w,i});
	}
	int w=res.second;
	for(int i=0;i<x;i++) t[i]-=(a[w]>>i&1);
	sum+=res.first,a[w]+=res.first,t[x]++;
	for(int i=x-1;i>=0;i--)
		if(!t[i])
		{
			solve(i);
			break;
		}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&Q);
		for(int i=0;i<=30;i++) t[i]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			for(int j=0;j<=30;j++)
				t[j]+=a[i]>>j&1;
		}
		sum=0;
		for(int i=0;i<=30;i++)
		{
			if(t[i]) f[i]=0;
			else solve(i),f[i]=sum;
		}
		while(Q--)
		{
			int x;
			scanf("%d",&x);
			int ans=0;
			for(int i=0;i<=30;i++)
				if(x>=f[i]) ans++;
			printf("%d\n",ans);
		}
	}
}