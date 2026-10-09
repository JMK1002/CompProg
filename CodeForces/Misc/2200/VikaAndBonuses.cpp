#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int s, k;
    cin>>s>>k;

    int ans=s*k;
    if(s%10==0 || k==1){
        cout<<ans<<"\n";
        return;
    }

    if(s%10==5){
        s+=(s%10);
        k--;
        ans=max(ans,(s*k));
        cout<<ans<<"\n";
        return;
    }
    
    if(s%2==1){
        s+=(s%10);
        k--;
    }

    ans=max(ans,(s*k));
    if(k<=10){
        ans=max(ans,(s*k));
        for(int i=1; i<=k; i++){
            s+=(s%10);
            ans=max(ans,(k-i)*s);
        }
        cout<<ans<<"\n";
        return;
    }

    int st, co, en;

    for(int i=1; i<=4; i++){
        co=(k-(i-1))/4;
        en=(k-(i-1))%4;

        int val[]={0,co,min(co,max(0ll,(5*en+20*co-s)/40)),max(0ll,min(co,((5*en+20*co-s)/40+1)))};
        for(int j=0; j<4; j++){
            ans=max(ans,(en+4*(co-val[j]))*(s+20*val[j]));
        }

        s+=(s%10);
    }

    cout<<ans<<"\n";
}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
