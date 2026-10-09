
// LUOGU_RID: 103303807
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=52;
int T,n,m,l[N],r[N];
char ch[N][N];
multiset<int> ls;
signed main(){
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n>>m,ls.clear();
		for(int i=1;i<=n;i++){
			l[i]=m+1,r[i]=0;
			for(int j=1;j<=m;j++){
				cin>>ch[i][j];
				if(ch[i][j]=='.') continue;
				ls.insert(j),l[i]=min(l[i],j),r[i]=max(r[i],j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=l[i];j<=r[i];j++){
				if(ch[i][j]=='.') ch[i][j]='#';
				else ls.erase(ls.find(j));
			}
			if(ls.empty()) continue;
			if(*ls.begin()<l[i]) l[i+1]=min(l[i+1],l[i]);
			else l[i+1]=min(r[i],*ls.begin());
			if(*ls.rbegin()>r[i]) r[i+1]=max(r[i+1],r[i]);
			else r[i+1]=max(l[i],*ls.rbegin());
		}
		for(int i=1;i<=n;i++) {for(int j=1;j<=m;j++) cout<<ch[i][j]; cout<<endl;}
	}return 0;
}