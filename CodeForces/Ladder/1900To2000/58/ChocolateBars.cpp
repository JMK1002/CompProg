// Hydro submission #64d5742da77a7d46af8b5dba@1691710509181
#include<bits/stdc++.h>
using namespace std;
long long dp[35][35][55];
int main()
{
    for(int i=0;i<=30;i++)
        for(int k=1;k<=50;k++)
            dp[i][0][k]=dp[0][i][k]=INT_MAX;
    for(int i=1;i<=30;i++)
        for(int j=1;j<=30;j++)
        {
            for(int k=1;k<min(i*j,51);k++)
            {
                dp[i][j][k]=INT_MAX;
                for(int l=0;l<=i;l++)
                    for(int t=0;t<=k;t++)
                        dp[i][j][k]=min(dp[i][j][k],dp[l][j][t]+dp[i-l][j][k-t]+j*j);
                for(int l=0;l<=j;l++)
                    for(int t=0;t<=k;t++)
                        dp[i][j][k]=min(dp[i][j][k],dp[i][l][t]+dp[i][j-l][k-t]+i*i);
            }
            for(int k=i*j+1;k<=50;k++)
                dp[i][j][k]=INT_MAX;
        }
    //for(int i=1;i<=2;i++)
    //	for(int j=1;j<=2;j++)
    //		for(int k=1;k<=4;k++)
    //			cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        cout<<dp[n][m][k]<<endl;
    }
}