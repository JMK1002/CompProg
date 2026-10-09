#include<bits/stdc++.h>
typedef long long ll;
ll pw(ll p,ll d,ll M){return d?(pw((p*p)%M,d>>1,M)*(d&1?p:1))%M:1LL;}
ll fun(ll n, ll p){return n?n/p+fun(n/p,p):0;}
main(){
    ll x,n,M=1e9+7,a,p,i;
    std::cin>>x>>n;
    for(i=p=1;++i*i<=x;p%=M)
        if(x%i<1)
            for(p*=pw(i,fun(n,i),M);x%i<1;x/=i);
    if(x^1) p*=pw(x,fun(n,x),M), p%=M;
    std::cout<<p;
}