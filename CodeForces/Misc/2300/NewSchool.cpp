#include<bits/stdc++.h>
using namespace std;
#define lf long double
#define N 100005

int _,n,m,a[N],p[N],d[N],e[N],f[N];
lf b[N];
pair<lf,int> B[N];
vector<int> c[N];

int main(){ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>_;
	while(_--){
		cin>>n>>m;
		for(int i=1;i<=n;++i) cin>>a[i];
		for(int i=1;i<=m;++i){
			int k;cin>>k;c[i].resize(k),b[i]=0;
			for(int j=0;j<k;++j) cin>>c[i][j],b[i]+=c[i][j];
			b[i]/=k,B[i]={-b[i],i};
		}
		sort(a+1,a+n+1,greater<int>()),sort(B+1,B+m+1);
		for(int i=1;i<=m;++i){
			d[i]=d[i-1]+(-B[i].first>a[i+1]),
			e[i]=e[i-1]+(-B[i].first>a[i]),
			f[i]=f[i-1]+(-B[i].first>a[i-1]),
			p[B[i].second]=i;
		}
		for(int i=1;i<=m;++i)
			for(auto x:c[i]){
				lf t=(b[i]*c[i].size()-x)/(c[i].size()-1.0);
				int o=lower_bound(B+1,B+m+1,make_pair(-t,i))-B;
				if(o>p[i]){
					if(t>a[o-1]||e[p[i]-1]+f[o-1]-f[p[i]]+e[m]-e[o-1]) putchar('0');
					else putchar('1');
				}
				else{
					if(t>a[o]||e[o-1]+d[p[i]-1]-d[o-1]+e[m]-e[p[i]]) putchar('0');
					else putchar('1');
				}
			}
		puts("");
	}
	return 0;
}