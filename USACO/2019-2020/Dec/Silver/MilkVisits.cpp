//
// Created by JMKov on 1/2/2024.
//
#include <iostream>
#include <set>
#include <fstream>

using namespace std;

const long long bt = 30;

long long n, m;
long long parent[100004][bt];
pair<long long, long long> cnt[100004];
bool breed[100004]; // true is G false is H
set<long long> adj[100004];
pair<long long, long long> times[100004];
long long timer = 0;

void build() {
    for (long long i = 1; i < bt; i++) {
        for (long long j = 0; j < n; j++) {
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
        }
    }
}

bool ancestor(long long a, long long b) {
    return (times[a].first >= times[b].first && times[a].second <= times[b].second);
}

void dfs(long long v, long long p, pair<long long, long long> amnt) {
    times[v].first = timer;
    timer++;

    cnt[v] = amnt;
    if (breed[v]) amnt.first++;
    else amnt.second++;

    parent[v][0] = p;
    adj[v].erase(p);
    for (long long edge : adj[v]) {
        dfs(edge, v, amnt);
    }
    timer++;
    times[v].second = timer;
}

long long lca(long long a, long long b) {
    long long ret = a;
    for (long long i = bt - 1; i >= 0; i--) {
        if (!ancestor(b, parent[ret][i])) ret = parent[ret][i];
    }
    if (ancestor(b, ret)) return ret;
    return parent[ret][0];
}

int main() {
    ifstream in("milkvisits.in");
    ofstream out("milkvisits.out");
//    ifstream in("C:\\Users\\JMKov\\IdeaProjects\\CompCoding\\USACO\\2019-2020\\Dec\\Silver\\milkvisits.in");
//    ofstream out("C:\\Users\\JMKov\\IdeaProjects\\CompCoding\\USACO\\2019-2020\\Dec\\Silver\\milkvisits.out");
    in >> n >> m;

    for (long long i = 0; i < n; i++) {
        char c;
        in >> c;
        breed[i] = (c == 'G');
        if (breed[i]) cnt[i].first++;
        else cnt[i].second++;
    }

    for (long long i = 0; i < n - 1; i++) {
        long long x, y;
        in >> x >> y;
        x--; y--;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    dfs(0, 0, {0, 0});
    build();

    while (m--) {
        long long x, y;
        char c;
        in >> x >> y >> c;
        x--; y--;
        long long anc = lca(x, y);
        pair<long long, long long> amnt;
        amnt.first = cnt[x].first + cnt[y].first - 2 * cnt[anc].first + breed[x] + breed[y];
        amnt.second = cnt[x].second + cnt[y].second - 2 * cnt[anc].second + (!breed[x]) + (!breed[y]);

        cout << amnt.first << " " << amnt.second << endl;

        if (c == 'G') out << (amnt.first > 0);
        else out << (amnt.second > 0);
    }
    return 0;
}
//1 2
//2 3
//3 9
//3 10
//2 4
//4 6
//6 7
//6 8
//1 5
//5 11