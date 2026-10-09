#include "bits/stdc++.h"
using namespace std;
#define forn for (int i = 0; i < n; i++)
#define int long long
#define ed "\n"
#define cyes cout << "YES\n"
#define cno cout << "NO\n"
#define pb push_back
#define deb cout << "Hi\n"
#define pint pair<int, int>
#define sz(x) static_cast<int>((x).size())
const long long inf = 1000000000000000000;
const long long MOD = 1000000007;


void dbg_out(){cerr<<"\n";}
template<typename Head,typename... Tail>
void dbg_out(Head H,Tail... T){cerr<<' '<<H;dbg_out(T...);}
#define debug(...) cerr<<"("<<#__VA_ARGS__<<"):",dbg_out(__VA_ARGS__)

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------//


int main(){

    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("barnpainting.in", "r", stdin);
    // freopen("barnpainting.out", "w", stdout);

    int x, y; cin>>x>>y;
    int a = max(x, y);
    int b = min(x, y);

    if(a == b){
        cout << 0 << ed;
        return 0;
    }

    int d = a - b;
    vector<int> fac;
    for(int i = 1; i*i <= d; i++){
        if(d%i == 0){
            fac.pb(i);
            if(i*i != d) fac.pb(d/i);
        }
    }

    int lmn = inf;
    int kmn = inf;

    for(auto val: fac){
        int g = val;
        int mult = b/g + 1;
        if(b%g == 0) mult--;
        int k;
        while(true){
            int kk = mult*g - b;
            int gg = gcd(b+kk, a+kk);
            if(gg == g){
                k = kk;
                break;
            }
        }
        int l = (a+k)*(b+k);
        l /= g;
        if(lmn > l){
            lmn = l;
            kmn = k;
        }
        else if(lmn == l) kmn = min(k, kmn);

    }

    cout << kmn << ed;

}