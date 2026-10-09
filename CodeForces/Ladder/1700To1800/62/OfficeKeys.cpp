// LUOGU_RID: 111542135
#include<bits/stdc++.h>
using namespace std;
#define INF 2147483647
typedef long long ll;
ll n,k,p;
ll a[1010],b[2010];
ll dp[1010][2020];
int main()
{
    scanf("%lld%lld%lld",&n,&k,&p);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=k;i++)
        scanf("%lld",&b[i]);
    sort(a+1,a+n+1);
    sort(b+1,b+k+1);
    for(int i=1;i<=n;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<n;j++)
            dp[i][j]=INF;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=k;j++)
        {
            dp[i][j]=min(max(dp[i-1][j-1],abs(a[i]-b[j])+abs(b[j]-p)),dp[i][j-1]);
        }
    }
    printf("%lld",dp[n][k]);
    return 0;
}