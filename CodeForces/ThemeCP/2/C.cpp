#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;cin>>n;
		for(int i=1;i<=n-1;i++){
			cout<<3*n+9+2*(i-1)<<" ";
		}
		cout<<5*n+11<<"\n";
	}
	return 0;
}
