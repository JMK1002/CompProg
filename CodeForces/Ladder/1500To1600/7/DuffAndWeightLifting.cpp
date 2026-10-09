#include <bits/stdc++.h>
int  a[1001000],n,i,b,sum=0;
using namespace std;
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%d",&b);
        a[b]++;
    }
    for(i=0;i<=1001000;i++)
    {
        sum+=a[i]%2;
        a[i+1]+=a[i]/2;
    }
    cout<<sum;
}