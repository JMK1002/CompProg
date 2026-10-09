#include<bits/stdc++.h>
using namespace std;
const int N=1000500,C=30;
int n,q,lst[N],nxt[N][C];
char s[N];
inline void calc(int i){
	for(int j=0;j<C;++j)
		if(j==s[i+1]-'a')
			nxt[i][j]=i+1,lst[i+1]=nxt[lst[i]][j];
		else
			nxt[i][j]=nxt[lst[i]][j];
}
int main(){
	scanf("%s%d",s+1,&q),n=strlen(s+1);
	lst[0]=0,nxt[0][s[1]-'a']=1,lst[1]=0;
	for(int i=1;i<n;++i)
		calc(i);
	while(q--){
		int m;
		scanf("%s",s+n+1),m=strlen(s+n+1);
		for(int i=n;i<n+m;++i)
			calc(i),printf("%d ",lst[i+1]);
		puts("");
	}
}