#include <bits/stdc++.h>

using namespace std;

const int N = int(3e5) + 99;

int n, m;
int l[N], r[N], s[N];
int d[N];
int dx[N];
int res[N];
int nxt[N];

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; ++i){
        scanf("%d %d %d", s + i, l + i, r + i);
        --l[i], --r[i];
        if(s[i] == 1)
            ++d[l[i]], --d[r[i]];
    }

    memset(dx, -1, sizeof dx);
    int sum = 0;
    for(int i = 0; i < n - 1; ++i){
        sum += d[i];
        if(sum > 0)
            dx[i] = 0;
    }

    res[0] = n;
    for(int i = 1; i < n; ++i)
        res[i] = res[i - 1] + dx[i - 1];

    nxt[n - 1] = n - 1;
    for(int i = n - 2; i >= 0; --i){
        if(res[i] <= res[i + 1])
            nxt[i] = nxt[i + 1];
        else
            nxt[i] = i;
    }

    for(int i = 0; i < m; ++i){
        if(s[i] != (nxt[l[i]] >= r[i])){
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    for(int i = 0; i < n; ++i)
        printf("%d ", res[i]);
    puts("");

    return 0;
}                             	
