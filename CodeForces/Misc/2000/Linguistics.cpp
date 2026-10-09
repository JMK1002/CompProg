#include<bits/stdc++.h>
using namespace std;
int t, a, b, c, d;
string st;
void solve(){
    cin>>a>>b>>c>>d;
    cin>>st;
    int n = st.length(), cntA=0, fir=(st[0]-'A'), len=1, tot=0;
    for (int i=0; i<n; i++){
        cntA+=(st[i]=='A');
    }
    if (cntA!=a+c+d){
        puts("NO");
        return;
    }
    vector<int> q[2];
    st+=st[n-1];
    for (int i=1; i<=n; i++){
        if (st[i]==st[i-1]){
            if (len&1) tot+=len/2;
            else{
                q[fir].push_back(len/2);
            }
            fir=st[i]-'A';
            len=1;
        }else{
            len++;
        }
    }
    sort(q[0].begin(), q[0].end());
    sort(q[1].begin(), q[1].end());
    int i=0, j=0, s1=q[0].size(), s2=q[1].size();
    while (i<s1 && c>=q[0][i]) c-=q[0][i++];
    while (j<s2 && d>=q[1][j]) d-=q[1][j++];
    while (i<s1) tot+=q[0][i++]-1;
    while (j<s2) tot+=q[1][j++]-1;
    puts(c+d<=tot?"YES":"NO");
}
int main(){
    cin>>t;
    while (t){
        t--;
        solve();
    }
}