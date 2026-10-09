# include <bits/stdc++.h>
using namespace std;
#define N 504
#define F(z,x,y) for(int z=x;z<y;z++)
#define R return
int d[N][N];
int n,t,a[N],q[N];
int f(int i, int j){
    if(j<0) R -1;
    if(!i) R (j<1)?1:-1;
    if(d[i][j]+2) R d[i][j];
    int q = -1*(j!=1);
    F(k,0,i) if(a[k] < a[i]) q = max(q, f(k, j - !!(k-i+1)));
    if(q+1) q++;
    d[i][j] = q;
    R q;
}
int main(){
    t; cin>>t;
    while(t--){
        fill_n(&d[0][0], N * N, -2);
        cin>>n;
        F(i,0,n) cin>>a[i];
        a[n] = n+1; n++;
        vector<int> q(n+1, -1);
        F(j,0,n+1) q[j]=n-f(n-1, j);
        F(j,1,n) q[j]=min(q[j], q[j-1]),cout<<q[j]<<" ";
        cout << "\n";
    }
}
