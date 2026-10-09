#include<bits/stdc++.h>

using namespace std;

const int N = 300043;

int n;
int v[N];
map<vector<int>, long long> dp[N];

pair<int, vector<int>> go(vector<int> a, int x)
{
    if(x == 0)
        return {1, a};
    else
    {
        bool f = false;
        for(int i = 0; i < a.size() && !f; i++)
            if((a[i] & x) > 0)
            {
                f = true;
                a[i] = x;
            }
        int c = 0;
        if(!f)
        {
            c = 1;
            a.push_back(x);
        }
        return {c, a};
    }
}

long long calc(int i, vector<int> a)
{
    if(i == n) return 0ll;
    if(dp[i].count(a)) return dp[i][a];
    auto p = go(a, v[i]);
    return (dp[i][a] = p.first * 1ll * (n - i) + calc(i + 1, p.second));
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &v[i]);
    long long ans = 0;
    for(int i = 0; i < n; i++)
        ans += calc(i, vector<int>(0));
    printf("%lld\n", ans);    
}