//
// Created by JMKov on 6/18/2024.
//
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main()
{
    vector<int> ns(4);
    for(int i = 0; i < 4; i++)
        scanf("%d", &ns[i]);
    vector<vector<int>> cs(4);
    for(int i = 0; i < 4; i++)
    {
        cs[i].resize(ns[i]);
        for(int j = 0; j < ns[i]; j++)
            scanf("%d", &cs[i][j]);
    }
    vector<vector<vector<int>>> bad(3);
    for(int i = 0; i < 3; i++)
    {
        bad[i].resize(ns[i + 1]);
        int m;
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            y--;
            bad[i][y].push_back(x);
        }
    }
    vector<vector<int>> dp(4);
    dp[0] = cs[0];
    for(int i = 0; i < 3; i++)
    {
        dp[i + 1].resize(ns[i + 1]);
        multiset<int> s;
        for(int j = 0; j < ns[i]; j++)
            s.insert(dp[i][j]);
        for(int j = 0; j < ns[i + 1]; j++)
        {
            for(auto k : bad[i][j])
                s.erase(s.find(dp[i][k]));
            if(s.empty())
                dp[i + 1][j] = int(4e8 + 43);
            else
                dp[i + 1][j] = *s.begin() + cs[i + 1][j];
            for(auto k : bad[i][j])
                s.insert(dp[i][k]);
        }
    }
    int ans = *min_element(dp[3].begin(), dp[3].end());
    if(ans > int(4e8))
        ans = -1;
    cout << ans << endl;
}