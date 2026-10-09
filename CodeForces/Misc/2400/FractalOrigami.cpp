#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define asc(i,a,n) for(I i=a;i<n;i++)
#define dsc(i,a,n) for(I i=n-1;i>=a;i--)
#define forw(it,x) for(A it=(x).begin();it!=(x).end();it++)
#define bacw(it,x) for(A it=(x).rbegin();it!=(x).rend();it++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
#define all(x) (x).begin(),(x).end()
#define sz(x) (I)((x).size())
#define clr(x) (x).clear()
#define U unsigned
#define I long long int
#define S string
#define C char
#define D long double
#define A auto
#define B bool
#define CM(x) complex<x>
#define V(x) vector<x>
#define P(x,y) pair<x,y>
#define OS(x) set<x>
#define US(x) unordered_set<x>
#define OMS(x) multiset<x>
#define UMS(x) unordered_multiset<x>
#define OM(x,y) map<x,y>
#define UM(x,y) unordered_map<x,y>
#define OMM(x,y) multimap<x,y>
#define UMM(x,y) unordered_multimap<x,y>
#define BS(x) bitset<x>
#define L(x) list<x>
#define Q(x) queue<x>
#define PBS(x) tree<x,null_type,less<I>,rb_tree_tag,tree_order_statistics_node_update>
#define PBM(x,y) tree<x,y,less<I>,rb_tree_tag,tree_order_statistics_node_update>
#define pi (D)acos(-1)
#define md 999999893
#define rnd randGen(rng)
I modex(I a,I b,I m){
  a=a%m;
  if(b==0){
    return 1;
  }
  I temp=modex(a,b/2,m);
  temp=(temp*temp)%m;
  if(b%2){
    temp=(temp*a)%m;
  }
  return temp;
}
I mod(I a,I b,I m){
  a=a%m;
  b=b%m;
  I c=__gcd(a,b);
  a=a/c;
  b=b/c;
  c=modex(b,m-2,m);
  return (a*c)%m;
}
int main(){
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<I> randGen;
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("out04.txt", "w", stdout);
  #endif
  I temp=md;
  I t;
  cin>>t;
  while(t--){
    I n;
    cin>>n;
    I b=modex(2,n/2,md)-1;
    I a;
    if(n%2){
      a=modex(2,n/2+1,md)-1;
    }else{
      a=modex(2,n/2,md)-1;
    }
    I temp=(a+1)*(a+1);
    temp%=md;
    temp-=2*b*b;
    temp%=md;
    I ans=mod(2*b,temp,md);
    ans+=md;
    ans%=md;
    cout<<ans<<"\n";
  }
  return 0;
}