#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int T,n;
ll a[200005];

int s[125][125],d[125][125];
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if (a[i]==0) i--,n--;
    }
    if (n>=121) printf("%d\n",3);
    else
    {
        memset(s,37,sizeof s);
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (a[i]&a[j]) s[i][j]=s[j][i]=1;
        memcpy(d,s,sizeof d);

        int ans=1000;
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                {
                    if (i!=j && j!=k && k!=i)
                    {
                        ans=min(ans,s[i][j]+d[j][k]+d[k][i]);
                        s[i][j]=min(s[i][j],s[i][k]+s[k][j]);
                    }
                }
        if (ans==1000) ans=-1;
        printf("%d\n",ans);
    }

}