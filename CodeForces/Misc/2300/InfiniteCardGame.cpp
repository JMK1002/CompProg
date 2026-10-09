#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;const int N=3e5+7;typedef pair<int,int>pa;
pa a[N],b[N];int x[N],y[N],ans,pos,sum,T_T,n,m,i,j;
int main(){
    for(scanf("%d",&T_T);T_T--;){
        for(scanf("%d",&n),ans=pos=sum=0,i=1;i<=n;++i)scanf("%d",&a[i].sc);
        for(i=1;i<=n;++i)scanf("%d",&a[i].fr);
        for(scanf("%d",&m),i=1;i<=m;++i)scanf("%d",&b[i].fr);
        for(i=1;i<=m;++i)scanf("%d",&b[i].sc);
        sort(a+1,a+n+1);sort(b+1,b+m+1);reverse(a+1,a+n+1);reverse(b+1,b+m+1);
        for(i=1;i<=n;++i)x[i]=max(x[i-1],a[i].sc);
        for(i=1;i<=m;++i)y[i]=max(y[i-1],b[i].sc);
        for(i=1;i<=n;++i){
            while(pos<m&&a[i].fr<b[pos+1].fr)pos++;
            if(pos==0)ans=i;
            else{
                if(x[ans]>y[pos])ans=i;else if(x[i]>y[pos])sum=i;
            }
        }
        printf("%d ",ans);if(ans>sum)sum=ans;printf("%d %d\n",sum-ans,n-sum);
    }
}