#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define lep(i, a, b) for(int i = (a); i >= (b); i--)
#define pll(x) cout << (x) << '\n';
#define pli(x) cout << (x) << ' ';
#define sci(x) cin >> x;
#define x first
#define y second
#define pb push_back

const int N = 2e6 + 10;

ll n, m, k, g;
const ll p = 998244353;
ll fact[N], infact[N];

ll qmi(ll a, ll b)
{
    ll res = 1;
    for(; b; b >>= 1, a = a * a % p) if(b & 1) res = res * a % p;
    return res;
}

void init()
{
    fact[0] = infact[0] = 1;
    for(ll i = 1; i <= N - 1; i++) fact[i] = fact[i - 1] * i % p;
    infact[N - 1] = qmi(fact[N - 1], p - 2);
    for(ll i = N - 2; i >= 1; i--) infact[i] = infact[i + 1] * (i + 1ll) % p;
}

ll C(ll a, ll b)
{
    //cout<<fact[a]<<' '<<infact[b]<<' '<<infact[a - b]<<'\n';
    if(a <= b) return 1;
    return fact[a] * infact[b] % p * infact[a - b] % p;
}

void solve()
{
    cin >> n >> k;
    if(0);
    else
    {
        ll sy = n % (2ll * k), res2 = 0, res1 = 0;
        //cout << "? " << C(0, 0) << '\n';
        for(ll x = 0; x <= k - 1 && 2ll * x <= sy; x++)
        {
            //cout << "? " << C(k - 1, x) << ' ' << C(k + 1 - x, sy - 2ll * x) << '\n';
            //cout << "? " << C(k + 1 - x, sy - 2ll * x) << '\n';
            if(sy - x * 2 > k + 1 - x) continue;
            (res2 += C(k - 1, x) * C(k + 1 - x, sy - 2ll * x) % p) %= p;
        }
        ll y = n / (2ll * k);
        res1 = (y * sy + y * (y - 1) / 2ll * 2ll * k);

        if(res1 == 0)
        {
            cout << 0 << ' ' << C(k - 1, n - k - 1) << '\n';
            return;
        }
        else
        {
            res2 = ((res2 % p + p) % p);
            cout << res1 << ' ' << res2 << '\n';
        }
    }
}

int main()
{
    int T = 1;
    cin >> T;
    init();
    //pll(infact[N - 1])
    //return 0;
    while(T--)
    {
        solve();
    }

    return 0;
}
