#include<bits/stdc++.h>
using namespace std;
auto wk=[](){
    int n,i,j,z=1e9,r,h=0;
    cin>>n,++n;
    vector<int>v(n,0),f(n,0);
    for(i=1;i<n;++i)cin>>j,++v[j];
    partial_sum(begin(v),end(v),begin(f));
    auto cal=[](int x){
        for(int i=1;;i<<=1)if(i>=x)return i-x;
    };
    for(i=0;i<n;z=min(z,r+cal(h)),h+=v[i++]){
        for(r=1e9,j=1;j<=n;j<<=1){
            auto it=upper_bound(begin(f),end(f),j+h);
            if(it==begin(f))continue;
            --it,r=min(r,j-(*it-h)+cal(f.back()-*it));
        }
    }
    cout<<z<<'\n';
};
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int T;for(cin>>T;T--;)wk();
}