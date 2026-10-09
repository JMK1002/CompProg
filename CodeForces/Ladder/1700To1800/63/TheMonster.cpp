//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ld = long double;

#define X first
#define Y second

//const ll mod = 1000000007;
const ll mod = 998244353;


int dp[5001][5001];

void solve()
{
    string s;
    cin >> s;
    ll n = s.length();
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) dp[i][j] = 1;
    }
    for (ll st=0;st<n;st++)
    {
        int B = 0;
        for (ll r=st;r<n;r++)
        {
            if (B<0)
            {
                dp[st][r] = 0;
                continue;
            }
            if (s[r]==')') B--;
            else B++;
            if (B%2!=0) dp[st][r] = 0;
        }
    }
    for (ll r=0;r<n;r++)
    {
        int B = 0;
        for (ll st=r;st>=0;st--)
        {
            if (B<0)
            {
                dp[st][r] = 0;
                continue;
            }
            if (s[st]=='(') B--;
            else B++;
            if (B%2!=0) dp[st][r] = 0;
        }
    }
    ll A = 0;
    for (ll i=0;i<n;i++)
    {
        for (ll j=i;j<n;j++) A += dp[i][j];
    }
    cout << A << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    ll T;
    T = 1;
    //cin >> T;
    while (T--) solve();
}