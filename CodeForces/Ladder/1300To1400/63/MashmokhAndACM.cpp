#include <bits/stdc++.h>

using namespace std;

const int MAX = 2010;
vector<int> divisors[MAX];
int dp[MAX][MAX], M = 1e9+7;

int solve(int num, int m)
{
    if(num == 1) return 1;
    if(dp[num][m] != -1) return dp[num][m];

    int n = divisors[m].size(), ret = 0;
    for(int i = 0; i < n; i++)
        ret = (ret + solve(num-1, divisors[m][i])) % M;

    dp[num][m] = ret;
    return ret;
}

int main()
{
    for(int i = 1; i < MAX; i++)
        for(int j = i; j < MAX; j+=i)
            divisors[j].push_back(i);
    memset(dp, -1, sizeof dp);

    int n, k, ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        ans = (ans + solve(k, i)) % M;
    cout << ans;
    return 0;
}