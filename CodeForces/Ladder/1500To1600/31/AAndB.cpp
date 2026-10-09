#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll N=1e7+7;

int main() {
// 	cout<<"GfG!";
    ll t; cin>>t; while(t--)
    {
        ll a,b; cin>>a>>b;
        for(ll i=0; i<N ; i++)
        {
            if(a==b) { cout<<0<<endl; break; }
            if( (i*(i+1)+2*(a-b) )>-1&&  (i*(i+1)+2*(a-b) )%4==0 && ( i*(i+1)-2*(a-b) )>-1 && ( i*(i+1)-2*(a-b) )%4==0 )
            {
                cout<<i<<endl; break;
            }
        }
    }
    return 0;
}