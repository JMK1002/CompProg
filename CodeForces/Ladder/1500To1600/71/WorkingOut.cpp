#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define nn 1005
ll boy_start[nn][nn];
ll boy_end[nn][nn];
ll girl_start[nn][nn];
ll girl_end[nn][nn];
ll calorie[nn][nn];

void calculate(ll n,ll m)
{
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
        {
            boy_start[i][j]=calorie[i][j]+max(boy_start[i-1][j],boy_start[i][j-1]);
        }
    }

    for(ll i=n;i>=1;i--)
    {
        for(ll j=m;j>=1;j--)
        {
            boy_end[i][j]=calorie[i][j]+max(boy_end[i+1][j],boy_end[i][j+1]);
        }
    }

    for(ll i=n;i>=1;i--)
    {
        for(ll j=1;j<=m;j++)
        {
            girl_start[i][j]=calorie[i][j]+max(girl_start[i+1][j],girl_start[i][j-1]);
        }
    }

    for(ll i=1;i<=n;i++)
    {
        for(ll j=m;j>=1;j--)
        {
            girl_end[i][j]=calorie[i][j]+max(girl_end[i-1][j],girl_end[i][j+1]);
        }
    }

    ll ans=INT_MIN;
    for(ll i=2;i<n;i++)
    {
        for(ll j=2;j<m;j++)
        {
            ll ans1=(boy_start[i][j-1]+boy_end[i][j+1]+girl_start[i+1][j]+girl_end[i-1][j]);
            ll ans2=(boy_start[i-1][j]+boy_end[i+1][j]+girl_start[i][j-1]+girl_end[i][j+1]);
            ans=max(ans,max(ans1,ans2));
        }
    }
    cout<<ans<<endl;
}

int main()
{
    memset(boy_start,0,sizeof(boy_start));
    memset(boy_end,0    ,sizeof(boy_end));
    memset(girl_start,0,sizeof(girl_start));
    memset(girl_end,0,sizeof(girl_end));
    memset(calorie,0,sizeof(calorie));
    ll n,m;
    // freopen("input.txt","r",stdin);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=m;j++)
            cin>>calorie[i][j];
    }
    calculate(n,m);
}