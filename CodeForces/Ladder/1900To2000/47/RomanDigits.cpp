#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
const int N = 20;
set<int> ans;
int n;
int cal[5] = {0, 1, 5, 10, 50};
int sel[N];
void dfs(int x)
{
    // cout << x << endl;
    if (x == n + 1)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
            res += cal[sel[i]];
        ans.insert(res);
        return;
    }
    for (int i = 1; i <= 4; i++)
        sel[x] = i, dfs(x + 1);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n <= 11)
    {
        dfs(1);
        cout << ans.size() << endl;
    }
    else
    {
        int N = n;
        n = 11;
        dfs(1);
        cout << ans.size() + (N - 11) * 49 << endl;
    }
}