#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll _=4e5+5;
ll N,n,t,a[_],b[_],i,j;
void P(){
	cin>>n;t=0;
	for(i=0;i<n;i++){
		cin>>a[i];
		if(!b[a[i]])t=(t?-1:a[i]);
	}
	if(t<0){cout<<"-1\n";return;}
	if(!t){cout<<"2\n";return;}
	for(i=0;i<n;i++)if(a[i]%t>0&&2*t>a[i]-b[a[i]]){cout<<"-1\n";return;}
	cout<<t<<'\n';
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(i=2;i<_;i++)if(!b[i])for(j=i*i;j<_;j+=i)if(!b[j])b[j]=i;
	cin>>N;while(N--)P();
}