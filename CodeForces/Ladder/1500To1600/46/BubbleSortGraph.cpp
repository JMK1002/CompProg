#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    vector<int>a;
    while(n--){
        cin>>x;
        if(a.size()<1||x>a.back())a.push_back(x);
        else a[lower_bound(a.begin(),a.end(),x)-a.begin()]=x;}
    cout<<a.size()<<'\n';
    return 0;}