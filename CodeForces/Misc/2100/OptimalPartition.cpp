#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp0,mp1;
int T,n;
long long p,dp,x;
void solve(){
    scanf("%d",&n);
    p=dp=0;
    mp0.clear();
    mp1.clear();
    mp0[0]=0;
    mp1[0]=0;
    mp1[-LONG_LONG_MAX]=-1000005;
    mp1[LONG_LONG_MIN]=500005;
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        p+=x;
        dp--;
        if(mp0.find(p)!=mp0.end()) dp=max(dp,mp0[p]);
        auto it=prev(mp1.lower_bound(p));
        dp=max(dp,i+it->second);
        mp0[p]=dp;
        if(mp1.find(p)==mp1.end()||mp1[p]<dp-i) mp1[p]=dp-i;
        while(mp1.upper_bound(p)->second<dp-i) mp1.erase(mp1.upper_bound(p));
    }
    printf("%d\n",dp);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}