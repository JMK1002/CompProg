//
// Created by JMKov on 12/24/2023.
//

#include <iostream>
#include <set>
#include <vector>

using namespace std;

const long long INF = INT64_MAX;

set<pair<long long, pair<long long, long long>>> flights[200004];
long long layoverTimes[200004];
long long dist[200004];
set<pair<long long, long long>> nodes;

int main() {
    cin.tie();
    istream::sync_with_stdio(0);

    long long n, m;
    cin >> n >> m;
    for (long long i = 0; i < n; i++) dist[i] = INF;
    for (long long i = 0; i < m; i++) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        a--; c--;
        flights[a].insert({b, {c, d}});
    }
    for (long long i = 0; i < n; i++) cin >> layoverTimes[i];


    dist[0] = 0;
    for (long long i = 0; i < n; i++) nodes.insert({dist[i], i});

    while (!nodes.empty()) {
        long long node = (*nodes.begin()).second;
        if (dist[node] == INF) break;

        nodes.erase(nodes.begin());
        long long flightTime = (node == 0) ? 0 : layoverTimes[node] + dist[node];

        auto start = flights[node].lower_bound({flightTime, {-1, -1}});
        vector<pair<int, pair<int, int>>> del;
        for ( ; start != flights[node].end(); start++) {
            long long nextNode = (*start).second.first;
            if (dist[nextNode] > (*start).second.second) {
                nodes.erase({dist[nextNode], nextNode});
                dist[nextNode] = (*start).second.second;
                nodes.insert({dist[nextNode], nextNode});
                del.push_back(*start);
            }
        }
        for (pair<int, pair<int, int>> element : del) flights[node].erase(element);
    }
    for (long long i = 0; i < n; i++) cout << ((dist[i] == INF) ? -1 : dist[i]) << endl;
    return 0;
}