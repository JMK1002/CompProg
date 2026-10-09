//
// Created by JMKov on 7/21/2023.
//
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

vector<pair<long long, long long>> path;
long long ans[200010];
long long arr[200010];
long long pre[200010];
long long dist[200010];
set<pair<long long, long long>> children[200010];

void dfs(long long v) {
    for (pair<long long, long long> i : children[v]) {
        path.emplace_back(dist[i.first], i.first);
        dfs(i.first);
        path.pop_back();
    }
    long long end = lower_bound(path.begin(), path.end(), *new pair<long long, long long>(dist[v] - arr[v], -1))->second;
    pre[end]--;
    pre[v]++;
}

long long calcAns(long long v) {
    for (pair<long long, long long> i : children[v]) {
        ans[v] += calcAns(i.first);
    }
    return ans[v] + pre[v];
}

int main() {
    long long n;
    cin >> n;
    for (long long i = 0; i < n; i++) cin >> arr[i];
    pair<long long, long long> parent[n];
    parent[0] = {-1, -1};
    for (long long i = 1; i < n; i++) {
        long long p, w;
        cin >> p >> w;
        p--;
        children[p].insert({i, w});
        parent[i] = {p, w};
    }
    queue<long long> q;
    q.push(0);
    while (!q.empty()) {
        long long v = q.front();
        q.pop();
        for (auto edge : children[v]) {
            dist[edge.first] = dist[v] + edge.second;
            q.push(edge.first);
        }
    }
    path.emplace_back(0, 0);
    dfs(0);
//    for (long long i = 0; i < n; i++) cout << pre[i] << " ";
//    cout << endl;
    calcAns(0);
    for (long long i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}