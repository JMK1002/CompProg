#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll l,r,n,ans,m,a,b;
ll bin(ll a, ll n)
{
	ll ans=1;
	while(n)
	{
		if(n&1)
			ans*=a;
		a*=a;
		n/=2;
	}
	return ans;
}
int main()
{
	cin>>n>>l>>r;
	if(n==1)
	{
		cout<<r-l+1;
		return 0;
	}
	if(n>25)
	{
		cout<<0;
		return 0;
	}
	if(n>2)
	{
		m=pow(2,log2(1e8)/(n-1));
		m=min(m,3200LL);
		for(ll i=1;i<=m;i++)
			for(ll j=i+1;j<=m;j++)
				if(__gcd(i,j)==1)
				{
					a=bin(j,n-1);
					b=bin(i,n-1);
					if(l*a/b>r)
						continue;
					ans+=(r*b/a)/b-(l-1)/b;
				}
		cout<<ans*2;
		return 0;
	}
	cout<<(r-l+1)*(r-l);
}
