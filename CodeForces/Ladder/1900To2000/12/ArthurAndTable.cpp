#include<bits/stdc++.h>
#define endl '\n'
#define x first
#define y second
#define pb push_back
#define lowbit(x) (x & (-x))
#define point(n) cout << fixed << setprecision(n)
#define YN(flag) cout << (flag ? "YES" : "NO") << endl
#define debug(x) cout << "debug " << x << endl
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> PLL;
typedef pair<ull,ull> UPLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;
const int N = 1000010, M = 2 * N;


int n, m;
PII p[N];
int d[N];
int suf[N];

void solve()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> p[i].x;
    for(int i = 1; i <= n; i++)
        cin >> p[i].y;
    sort(p + 1, p + 1 + n);
    for(int i = n; i >= 1; i--)
        suf[i] = suf[i + 1] + p[i].y;
    int ans = INF;
    for(int i = 1; i <= n; i++)
    {
        int j = i;
        while(j + 1 <= n && p[j + 1].x == p[i].x)
            j++;
        int len = max(0, j - (j - i + 1) * 2 + 1);
        int tmp = 0;
        for(int k = 1; k <= 200; k++)
        {
            int c = min(d[k], len);
            tmp += c * k;
            len -= c;
        }
        ans = min(ans, tmp + suf[j + 1]);
        for(int k = i; k <= j; k++)
            d[p[k].y]++;
        i = j;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int _ = 1;
    //cin >> _;
    while(_--)
    {
        solve();
    }
}