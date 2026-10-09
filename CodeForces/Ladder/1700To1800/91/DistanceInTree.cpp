#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

const int N_MAX = 50e3;
const int K_MAX = 500;

vector<int> tree[1 + N_MAX];
int64 globalAnswer = 0; int n, k;
int64 cnt[1 + N_MAX][1 + K_MAX];
void DFS (int root, int p) {
    for (int node : tree[root])
        if (node != p)
            DFS (node, root);

    cnt[root][0] = 1;
    for (int node : tree[root]) {
        if (node != p) {
            for (int t = 0; t < k; t ++)
                globalAnswer += cnt[root][t] * cnt[node][k - t - 1];
            for (int t = 1; t <= k; t ++)
                cnt[root][t] += cnt[node][t - 1];
        }
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i < n; i ++) {
        int u, v; cin >> u >> v;
        tree[u].push_back (v);
        tree[v].push_back (u);
    }
    DFS (1, 0);
    cout << globalAnswer;
    return 0;
}
