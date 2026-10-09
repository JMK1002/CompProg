#include<bits/stdc++.h>
using namespace std;
int n,T;
char s[200005];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);
		long long a=0,b=0,x=0;
		for(int i=n;i;i--){
			if(s[i]=='B'){
				a++;
				b++;
				if(i&1)b--;
			}else{
				x+=a;
			}
		}
		a=(a/2-b);
		if(a<0)a=-a;
		printf("%lld\n",(a+x)/2);
	}
	return 0;
}