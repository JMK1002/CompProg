//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")
//#pragma expected_value
//#pragma isolated_call
//#pragma disjoint

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define setpre(i) setprecision(i)<<fixed
#define foru(i, a, b) for(int i=a;i<=b;++i)
#define ford(i, a, b) for(int i=a;i>=b;--i)
#define mp make_pair
#define moo cout<<"moo "
#define fi first
#define se second

ll lmod = 1e9 + 7;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool visited[500001];
int comp[500001];
vi order;
vi adj[500001], adj_t[500001];
int mn;

vi switches[200001];
bool state[200001];


void dfs1(int node){
    visited[node] = 1;
    for(int i: adj[node]) if(!visited[i]) dfs1(i);
    order.pb(node);
}

void dfs2(int node, int root){
    comp[node] = root;
    for(int i: adj_t[node]) if(comp[i] == -1) dfs2(i, root);
}

bool sat2(){
    memset(comp, -1, sizeof comp);
    foru(i, 0, mn - 1) if(!visited[i]) dfs1(i);
    reverse(order.begin(), order.end());
    int j = 0;
    foru(i, 0, mn - 1) if(comp[order[i]] == -1) dfs2(order[i], j++);
    for(int i = 0; i < mn; i += 2) if(comp[i] == comp[i + 1]) return false;
    return true;
}

void addedge(int a, bool na, int b, bool nb) {
    // na and nb signify whether a and b are to be negated
    a = 2*a ^ na;
    b = 2*b ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].pb(b); adj[neg_b].pb(a);
    adj_t[b].pb(neg_a); adj_t[a].pb(neg_b);
}

int main(){
//	freopen("input.inp", "r", stdin);
//	freopen("output.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    mn = 2 * m;
    foru(i, 1, n) cin >> state[i];
    foru(i, 0, m - 1){
        int x; cin >> x;
        while(x--){
            int y; cin >> y;
            switches[y].pb(i);
        }
    }
    foru(i, 1, n){
        if(state[i]){
            addedge(switches[i][0], 1, switches[i][1], 0);
            addedge(switches[i][1], 1, switches[i][0], 0);
        }
        else{
            addedge(switches[i][0], 0, switches[i][1], 0);
            addedge(switches[i][1], 1, switches[i][0], 1);
        }
    }

    if(sat2()) cout << "YES"; else cout << "NO";
//	fclose(stdout);
}