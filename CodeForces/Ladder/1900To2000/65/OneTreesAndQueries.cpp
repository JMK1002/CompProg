//
// Created by JMKov on 8/15/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adj[100003];
bool explored[100003];
int lifting[100003][40];
int tIn[100003];
int tOut[100003];
int t = 0;

void dfs(int v, int p) {
    explored[v] = true;
    tIn[v] = t;
    t++;
    lifting[v][0] = p;
    for (int i = 1; i < 40; i++) {
        lifting[v][i] = lifting[lifting[v][i - 1]][i - 1];
    }
    for (int edge : adj[v]) {
        if (explored[edge]) continue;
        dfs(edge, v);
    }
    tOut[v] = t;
    t++;
}

void init(int root) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 40; j++) {
            lifting[i][j] = n;
        }
        explored[i] = false;
    }
    explored[n] = true;
    tIn[n] = -1;
    tOut[n] = 2000000000;
    t = 0;
    dfs(root, n);
}

bool isAncestor(int a, int b) {
    return tIn[a] <= tIn[b] && tOut[b] <= tOut[a];
}

int calcDist(int a, int b) {
    int dist = 0;
    for (int i = 32; i >= 0; i--) {
        if (!isAncestor(lifting[a][i], b)) {
            a = lifting[a][i];
            dist += (1 << i);
        }
    }
    for (int i = 32; i >= 0; i--) {
        if (!isAncestor(lifting[b][i], a) ) {
            b = lifting[b][i];
            dist += (1 << i);
        }
    }
    return dist + !isAncestor(a, b) + !isAncestor(b, a);
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(0);
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 3; j++) cout << lifting[i][j] << " ";
//        cout << endl;
//    }
    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--; y--; a--; b--;
        int d = calcDist(a, x) + calcDist(b, y) + 1;
//        cout << d << endl;
        if ((k & 1) == (d & 1) && d <= k) {
            cout << "YES" << endl;
            continue;
        }
        d = calcDist(a, y) + calcDist(b, x) + 1;
//        cout << d << endl;
        if ((k & 1) == (d & 1) && d <= k) {
            cout << "YES" << endl;
            continue;
        }
//        if (q == 1) cout << "SDF" << endl;
        d = calcDist(a, b);
//        cout << d << endl;
        if ((k & 1) == (d & 1) && d <= k) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}