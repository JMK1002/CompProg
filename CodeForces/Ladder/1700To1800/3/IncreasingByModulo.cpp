#include<bits/stdc++.h>
#define maxn 300005
using namespace std;

int n,m,a[maxn];

bool check(int v){
    int pr = 0;
    for(int i=1;i<=n;i++){
        if(a[i] + v >= m && a[i] + v - m >= pr) pr = pr;
        else{
            if(a[i] + v >= pr) pr = max(pr , a[i]);
            else return 0;
        }
    }
    return 1;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int L = 0, R = m , mid;
    for(;L<R;){
        mid = (L+R) >> 1;
        if(check(mid)) R = mid;
        else L = mid + 1;
    }
    printf("%d\n",L);
}