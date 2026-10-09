#include <bits/stdc++.h>
using namespace std;

#define int long long

template<class T>bool chkmax(T &a,T b){return b>a?a=b,true:false;}
template<class T>bool chkmin(T &a,T b){return b<a?a=b,true:false;}

constexpr int inf=2e18;

void solve(){
	int n,m,x,y;
	cin>>n>>m>>x>>y;
	vector<string>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<int>cnt(m);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cnt[i]+=a[j][i]=='#';
		}
	}
	vector<vector<vector<int>>>dp(m,vector<vector<int>>(y+1,vector<int>(2,inf)));
	dp[0][1][0]=cnt[0];
	dp[0][1][1]=n-cnt[0];
	for(int i=1;i<m;i++){
		for(int j=1;j<=y;j++){
			chkmin(dp[i][j][0],dp[i-1][j-1][0]+cnt[i]);
			chkmin(dp[i][j][1],dp[i-1][j-1][1]+n-cnt[i]);
		}
		for(int j=x;j<=y;j++){
			chkmin(dp[i][1][0],dp[i-1][j][1]+cnt[i]);
			chkmin(dp[i][1][1],dp[i-1][j][0]+n-cnt[i]);
		}
	}
	int ans=inf;
	for(int i=x;i<=y;i++){
		for(int j=0;j<=1;j++){
			chkmin(ans,dp[m-1][i][j]);
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	solve();
	return 0;
}