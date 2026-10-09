#include<bits/stdc++.h>
using namespace std;
int n,j;
long long s, r;
int main(){
    cin>>n;
    while(n--){
        cin>>j;
        s+=j;
        r=min(r+j/2, s/3);
    }
    cout<<r;
}