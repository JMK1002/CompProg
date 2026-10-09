//
// Created by JMKov on 7/17/2023.
//
#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    queue<long long> q;
    map<long long, bool> mp;
    for (long long i = 0; i < n; i++) {
        long long v;
        cin >> v;
        q.push(v);
        mp[v] = true;
    }
    long long dir[2] = {-1, 1};
    long long count = 0;
    long long dist = 0;
    long long depth = 1;
    long long ans[m];
    while (!q.empty() && count < m) {
        long long s = q.size();
        for (long long i = 0; i < s && count < m; i++) {
            long long v = q.front();
            q.pop();
            for (long long d: dir) {
                if (mp[d + v]) continue;
                q.push(d + v);
                ans[count] = d + v;
                dist += depth;
                count++;
                mp[d + v] = true;
                if (count == m) break;
            }
        }
        depth++;
    }
    cout << dist << endl;
    for (long long i : ans) cout << i << " ";
    cout << endl;
    return 0;
}