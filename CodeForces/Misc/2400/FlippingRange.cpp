#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
int n,m,a[N],T;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		int g=0;
		for(int i=1,x;i<=m;++i) scanf("%d",&x),g=__gcd(g,x);
		ll ans0=0,ans1=0;
		for(int i=1;i<=g;++i){
			ll f0=0,f1=-1e18;
			for(int j=i;j<=n;j+=g){
				ll g0=max(f1-a[j],f0+a[j]),g1=max(f1+a[j],f0-a[j]);
				f0=g0;f1=g1;
			}
			ans0+=f0;ans1+=f1;
		}
		printf("%lld\n",max(ans0,ans1));
	}
	return 0;
}
