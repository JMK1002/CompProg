#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,lim=1e6;
int n;
int a[N],b[N],c[N];
bool check(int dv){
	for(int i=1;i<=n;i++)
		c[i]=a[i]%dv;
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++)
		if(c[i]!=b[i])return 0;
	return 1;
}
int sol(ll dlt){
	sort(b+1,b+n+1);
	if(dlt==0){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
			if(a[i]!=b[i])return -1;
		return (int)1e9;
	}
	int t=sqrt(dlt);
	for(int i=1;i<=t;i++){
		if(dlt%i==0){
			if(check(i))return i;
			if(dlt/i<=lim&&check(dlt/i))return dlt/i;
		}
	}
	return -1;
}
int main(){
	int cas;
	scanf("%d",&cas);
	while(cas--){
		ll A=0,B=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),A+=a[i];
		for(int i=1;i<=n;i++)scanf("%d",&b[i]),B+=b[i];
		cout<<sol(A-B)<<"\n";
	}
	return 0;
}