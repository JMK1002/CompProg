#include<bits/stdc++.h>
using namespace std;
string s;
long long int n,sb=0,k=0,j=1;
int main(){
    cin>>n;
    cin>>s;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1])
            sb+=j,j=k=1;
        else
            j++,sb+=k;
    }
    cout<<(n*(n-1))/2-sb<<endl;
    return 0;
}
