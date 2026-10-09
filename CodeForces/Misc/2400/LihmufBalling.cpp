#include <bits/stdc++.h>


using namespace std;
using ll = long long;
using vi = vector<int>;

void solve(){
    ll n = 0; cin >> n;
    int m = 0; cin >> m;
    ll res = 0;
    int argmax = 1;
    // initial pos is -1 for both players
    for (int k = 2; k <= m; ++k){
        vi visited(k);
        ll res_this = 0;
        for (int t = 0; t != k; ++t){
            // the t-th loop. find the first visit pos.
            ll steps = (t * n - (-1) + k - 1) / k;
            int x = (-1 + steps * k) % n;
            if (visited[x]){
                break;
            }
            visited[x] = 1;
            ll y = -1 + steps;  // pak chanek position
            // some more steps untils x surparss y
            ll step2 = (max(y - x + 1, 0LL) + k - 2) / (k - 1);
            x += step2 * k;
            if (x < n){
                ll step3 = (n - 1 - x) / k;
                res_this += (x + 1 + (x + 1 + step3 * k)) * (step3 + 1) / 2;
            }            
        }
        // cout << "k: " << k << " res_this: " << res_this << "\n";
        if (res_this > res){
            res = res_this;
            argmax = k;
        }
    }
    cout << argmax << "\n";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1; // cin >> t;
    while (t--) { solve(); }
}