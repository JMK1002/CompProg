#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n = (1ll << n);
        vector<vector<int>> g(n);
        map<pair<int, int>, int> m;
        for (int i = 1; i <= n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--, v--;
            m[{u, v}] = i-1;
            m[{v, u}] = i-1;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> ans(n);
        vector<int> res(n - 1);
        ans[0] = n;
        int R = 2 * n - 1;
        int L = n - 1;
        function<void(int, int, int)> dfs = [&](int u, int v, int lvl)
        {
            for (auto &i : g[u])
            {
                if (i != v)
                {
                    if (lvl & 1)
                    {
                        ans[i] = R--;
                        res[m[{i, u}]] = L--;
                    }
                    else
                    {
                        ans[i] = L--;
                        res[m[{i, u}]] = R--;
                    }
                    dfs(i, u, lvl + 1);
                }
            }
        };
        dfs(0, -1, 0);
        cout << 1 << "\n";
        for (auto &i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
        for (auto &i : res)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}