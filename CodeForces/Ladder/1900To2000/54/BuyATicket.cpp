//
// Created by JMKov on 8/9/2023.
//
#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define inf INT64_MAX

long long n, m;
vector<pair<long long, long long>> connections[200010];
long long costs[200010];

void dijkstra() {
    bool marked[n];
    for (long long i = 0; i < n; i++) marked[i] = false;
    set<pair<long long, long long>> srt;
    for (long long i = 0; i < n; i++) {
        srt.emplace(costs[i], i);
    }
    pair<long long, long long> p = (*srt.begin());
    marked[p.second] = true;
    srt.insert(p);
    while (!srt.empty()) {
        pair<long long, long long> v = *(srt.begin());
        srt.erase(srt.begin());
        marked[v.second] = true;
        for (pair<long long, long long> edge : connections[v.second]) {
            if (!marked[edge.first] && v.first + edge.second * 2 < costs[edge.first]) {
                srt.erase({costs[edge.first], edge.first});
                costs[edge.first] = v.first + edge.second * 2;
                srt.emplace(costs[edge.first], edge.first);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        connections[u].emplace_back(v, w);
        connections[v].emplace_back(u, w);
    }
    for (long long i = 0; i < n; i++) cin >> costs[i];
    dijkstra();
    for (long long i = 0; i < n; i++) cout << costs[i] << " ";
    cout << endl;
    return 0;
}