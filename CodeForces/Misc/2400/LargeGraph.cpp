#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int MAXN = 3000005;

int n, k;
int p[MAXN];
int arr[MAXN];
bool explored[MAXN];
vector<int> ind[MAXN];
set<int> adj[MAXN];

void dfs(int v) {
    if (explored[v]) return;
    explored[v] = true;
    for (int e : adj[v]) {
        dfs(e);
    }
}

void solve() {
    cin >> n >> k;
    set<int> hurr;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        // arr[i] = 1;
    }
    vector<int> actual;
    for (int i = 1; i < n; i++) actual.push_back(arr[i]);
    for (int i = 0; i < n; i++) actual.push_back(arr[i]);
    n = 2 * n - 1;
    for (int i = 0; i < n; i++) {
        int x = actual[i];
        while (x != 1) {
            hurr.insert(p[x]);
            if (ind[p[x]].empty() || ind[p[x]][ind[p[x]].size() - 1] != i) ind[p[x]].push_back(i);
            x /= p[x];
        }
    }
    for (int i : hurr) {
        for (int j = 1; j < ind[i].size(); j++) {
            if (ind[i][j] - ind[i][j - 1] > k) continue;
            adj[ind[i][j]].insert(ind[i][j - 1]);
            adj[ind[i][j - 1]].insert(ind[i][j]);
        }
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += !(explored[i]);
        dfs(i);
    }
    for (int i = 0; i < n / 2; i++) {
        if (actual[i] == 1) cnt += max(0, i);
        if (actual[n - i - 1] == 1) cnt += max(0, i);
    }
    if (actual[n / 2] == 1) cnt += max(0, n / 2);
    cout << cnt << endl;
    for (int i = 0; i <= n; i++) {
        arr[i] = 0;explored[i] = 0;adj[i].clear();
    }
    for (int i : hurr) ind[i].clear();
}

int main() {
    istream::sync_with_stdio(0);
    cin.tie(nullptr);
    for (int i = 2; i < MAXN; i++) {
        if (p[i]) continue;
        for (int j = i; j < MAXN; j += i) p[j] = i;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}