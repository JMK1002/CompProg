//
// Created by JMKov on 8/6/2023.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<pair<int, int>> roads[100010];
vector<pair<int, int>> trains;
vector<pair<int, int>> par[100010];
int dist[100010];

void djikstra(int s, int n) {
    bool marked[n];
    set<pair<int, int>> unmarked;
    for (int i = 0; i < n; i++) dist[i] = INT32_MAX;
    for (int i = 0; i < n; i++) marked[i] = false;
    dist[s] = 0;
    unmarked.emplace(0, s);
    while (!unmarked.empty()) {
        int v = (*unmarked.begin()).second;
        unmarked.erase(unmarked.begin());
        marked[v] = true;
        for (pair<int, int> edge : roads[v]) {
            if (marked[edge.first]) continue;
            if (dist[v] + edge.second < dist[edge.first]) {
                unmarked.erase({dist[edge.first], edge.first});
                dist[edge.first] = dist[v] + edge.second;
                par[edge.first].clear();
                par[edge.first].emplace_back(v, false);
                unmarked.emplace(dist[edge.first], edge.first);
            }
            else if (dist[v] + edge.second == dist[edge.first]) {
                par[edge.first].emplace_back(v, false);
            }
        }
        if (v == 0) {
            for (pair<int, int> edge : trains) {
                if (marked[edge.first]) continue;
                if (dist[v] + edge.second < dist[edge.first]) {
                    unmarked.erase({dist[edge.first], edge.first});
                    dist[edge.first] = dist[v] + edge.second;
                    par[edge.first].clear();
                    par[edge.first].emplace_back(v, true);
                    unmarked.emplace(dist[edge.first], edge.first);
                }
                else if (dist[v] + edge.second == dist[edge.first]) {
                    par[edge.first].emplace_back(v, true);
                }
            }
        }
    }
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        u--; v--;
        roads[u].emplace_back(v, x);
        roads[v].emplace_back(u, x);
    }
    for (int i = 0; i < k; i++) {
        int s, y;
        cin >> s >> y;
        s--;
        trains.emplace_back(s, y);
    }
    djikstra(0, n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool asdf = !par[i].empty();
        for (pair<int, int> j : par[i]) {
            if (!j.second) {
                asdf = false;
                break;
            }
//            cout << j.first << "." << j.second << " ";
        }
        cnt += asdf;
//        cout << endl;
    }
//    cout << endl;
//    for (int i = 0; i < n; i++) cout << dist[i] << " ";
//    cout << endl;
    cout << k - cnt << endl;
    return 0;
}