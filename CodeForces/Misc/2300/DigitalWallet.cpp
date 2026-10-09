    #include<bits/stdc++.h>
    int a[11][100001];
    long long dp[100005];
    int n,m,q;
    int main(){
    	scanf("%d%d%d",&n,&m,&q);
    	for(int i=1;i<=n;++i)
    		for(int j=1;j<=m;++j)
    			scanf("%d",&a[i][j]);
    	for(int i=1;i<=m;++i)
    		for(int j=1;j<=n;++j)
    			for(int k=i;k&&k>i-q;--k)
    				dp[k]=std::max(dp[k],dp[k-1]+a[j][i]);
    	printf("%lld",dp[m-q+1]);
    	return 0;
    }