#include <bits/stdc++.h>

using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b){
    return a.second < b.second;
}

int main(){
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> stmn, stmx;
    stmn.push_back({-1, -1});
    stmx.push_back({n, -1});
    long long ans = 0;
    int len = 0;
    set<pair<int, int>> cur;
    cur.insert({-1, 0});
    cur.insert({-1, 1});
    for (int i = 0; i < n; ++i){
        int x;
        scanf("%d", &x);
        --x;
        
        while (stmn.back().first > x){
            auto it = cur.lower_bound({stmn.back().second, 0});
            auto me = it;
            auto prv = it; --prv;
            ++it;
            len -= me->first - prv->first;
            if (it != cur.end() && it->second == 0)
                len += it->first - prv->first;
            cur.erase(me);
            stmn.pop_back();
        }
        len += i - cur.rbegin()->first;
        cur.insert({i, 0});
        stmn.push_back({x, i});
        
        while (stmx.back().first < x){
            auto it = cur.lower_bound({stmx.back().second, 1});
            auto me = it;
            auto prv = it; --prv;
            ++it;
            if (it != cur.end() && it->second == 0)
                len += me->first - prv->first;
            cur.erase(me);
            stmx.pop_back();
        }
        cur.insert({i, 1});
        stmx.push_back({x, i});
        
        ans += len;
    }
    printf("%lld\n", ans - n);
}
