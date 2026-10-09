//
// Created by JMKov on 6/4/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

int main(){
    // Code with Concentration
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n);
    ll ans = 1;
    for(ll i =0;i<n;i++){
        cin>>v[i];
    }
    if(n<=m){
        ll ans = 1;
        for(ll i =0;i<n;i++){
            for(ll j=i+1;j<n;j++){
                ans = ans*abs(v[i]-v[j]-0);
                ans = ans%m;
            }
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }

}