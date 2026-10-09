#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector <ll>;
 
void tc () {
    ll n, m, k;
    cin >> n >> m >> k;
    set <ll> st;
    for (ll id = 0; id < k; id++) {
        ll i, j;
        cin >> i >> j;
        if (j == 1) continue;
        if (n == 1 && j != 2) continue;
        if (st.count(j))
            st.erase(j);
        else
            st.insert(j);
    }
    cout << (st.size() > 0 ? "Mimo" : "Yuyu") << '\n';
}
 
int main () {
    cin.tie(nullptr) -> sync_with_stdio(false);
    ll T; cin >> T; while (T--) { tc(); }
    return 0;
}