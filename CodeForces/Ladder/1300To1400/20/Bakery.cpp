#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ul unsigned long long int
vector<int>v(100006, 0);

void solve(){
    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>>vmy(m, vector<int>(3, 0));
    for(int i=0; i<m; i++) cin>>vmy[i][0]>>vmy[i][1]>>vmy[i][2];

    if(k==0){
        cout<<-1;
        return;
    }
    while(k--){
        int t;
        cin>>t;
        v[t] = 1;
    }
    int ans = 1e9+7;
    for(int i=0; i<m; i++){
        int u = vmy[i][0], v1 = vmy[i][1], l = vmy[i][2];

        if(v[u] && !v[v1]) ans = min(ans, l);
        else if(!v[u] && v[v1]) ans = min(ans, l);
    }
    if(ans==(1e9+7)) cout<<-1;
    else cout<<ans;
}

int main(){

    solve();

    return 0;
}
