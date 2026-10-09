#include<bits/stdc++.h>
using namespace std;
int gs[2];
signed main(){
	int a,d,e,f;
	string b,c;
	cin>>a;
	for(int va=0;va<a;++va){
		cin>>b>>c;
		for(int v=0;v<2;++v){
			gs[v]=0;
		}
		for(int v=0;v<b.size();++v){
			++gs[b[v]-48];
		}
		for(int v=0;v<c.size();++v){
			--gs[c[v]-48];
		}
		d=0;
		for(int v=0;v<2;++v){
			if(gs[v]!=0){
				d=1;
				break;
			}
		}
		if(d){
			cout<<"-1\n";
			continue;
		}
		d=0;
		e=1;
		f=0;
		if(c[0]!=b[0])f=1;
		for(int v=1;v<c.size();++v){
			if(c[v]!=c[v-1]){
				for(;d<b.size();++d){
					++gs[b[d]-48];
					if(d==b.size()-1){
						++d;
						break;
					}
					if(b[d]!=b[d+1]&&b[d]==c[v-1]){
						if(gs[c[v-1]-48]>=e){
							++d;
							break;
						}
						++f;
					}
				}
				if(gs[c[v-1]-48]>e){
					f=-1;
					break;
				}
				gs[c[v-1]-48]=0;
				e=0;
			}
			++e;
		}
		cout<<f<<'\n';
	}
	return 0;
}
