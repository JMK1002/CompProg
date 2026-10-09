//
// Created by JMKov on 7/11/2023.
//
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<pair<long long, long long>> connections[100010];
long long dist[100010];
long long n;

void dijkstra(long long v) {
    bool explored[n];
    multiset<pair<long long, long long>> sorted;
    for (long long i = 0; i < n; i++) {
        dist[i] = INT64_MAX;
        explored[i] = false;
    }
    for (long long i = 1; i < n; i++) sorted.insert(*new pair<long long, long long>(INT64_MAX, i));
    sorted.insert(*new pair<long long, long long>(0, 0));
    dist[v] = 0;
    for (long long i = 0; i < n; i++) {
        pair<long long, long long> lowest = *sorted.begin();
//        for (auto j : sorted) {
//            cout << j.first << " " << j.second << endl;
//        }
//        cout << endl;
        explored[lowest.second] = true;
        sorted.erase(sorted.begin());
        for (pair<long long, long long> j : connections[lowest.second]) {
            if (dist[j.first] <= dist[lowest.second] + j.second || explored[j.first]) continue;
            sorted.erase(*new pair<long long, long long>(dist[j.first], j.first));
            dist[j.first] = dist[lowest.second] + j.second;
            sorted.insert(*new pair<long long, long long>(dist[j.first], j.first));
        }
    }
//    for (long long i = 0; i < n; i++) cout << dist[i] << " ";
//    cout << endl;
}


int main() {
    cin >> n;
    long long total = 0;
    for (long long i = 0; i < n - 1; i++) {
        long long x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        connections[x].emplace_back(y, w);
        connections[y].emplace_back(x, w);
        total += w;
    }
    dijkstra(0);
    long long ans = total * 2;
    for (long long i = 0; i < n; i++) {
        ans = min(ans, total * 2 - dist[i]);
    }
    cout << ans << endl;
}