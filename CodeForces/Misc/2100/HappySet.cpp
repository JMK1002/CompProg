#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,mod=998244353;
int a[N],n,k,pd,ans;
inline int fastpow(int x, int y){
    int z=1;
    for (; y; y>>=1,x=1ll*x*x%mod)
        if (y&1) z=1ll*z*x%mod;
    return z;
}
int main(){
    scanf("%d%d",&n,&k); pd=1;
    for (int i=0; i<=k; i++){
        pd=1ll*pd*(i+1)%mod;
        a[i]=1ll*pd*fastpow(i+1,k-i)%mod;
    } pd=1;
    for (int i=0; i<=n && i<=k; i++){
        ans=(ans+1ll*pd*(a[i]-(i==0?0:a[i-1])+mod))%mod;
        pd=1ll*pd*(n-i)%mod;
    }
    printf("%d\n",ans);
}
