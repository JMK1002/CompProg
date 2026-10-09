#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

typedef long long li;

const li INF64 = 1e18;

struct base{
    int x, w, c;
};

li area(const base &a, const base &b){
    return (a.c + b.c) * li(abs(a.x - b.x));
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    vector<base> a(n);
    forn(i, n) scanf("%d%d%d", &a[i].x, &a[i].w, &a[i].c);
    sort(a.begin(), a.end(), [](const base &a, const base &b){ return a.x > b.x; });
    vector<li> dp(n, -INF64);
    li ans = 0;
    forn(i, n){
        dp[i] = max(dp[i], -a[i].w * 200ll);
        for (int j = i + 1; j < n; ++j)
            dp[j] = max(dp[j], dp[i] + area(a[i], a[j]) * k - a[j].w * 200ll);
        ans = max(ans, dp[i]);
    }
    printf("%.15Lf\n", ans / (long double)(200));
    return 0;
}