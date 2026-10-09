
#include<bits/stdc++.h>
using namespace std;

set<int> S[26];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        S[s[i]-'a'].insert(i+1);
    }
    int q,op,l,r;
    char z;
    cin >> q;
    while(q--){
        cin >> op >> l;
        if(op==1){
            cin >> z;
            S[s[l-1]-'a'].erase(l);
            s[l-1]=z;
            S[s[l-1]-'a'].insert(l);
        }
        else{
            cin >> r;
            int ans=0;
            for(int i=0;i<26;i++){
                auto it=S[i].lower_bound(l);
                if(it!=S[i].end() && (*it)<=r)ans++;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}