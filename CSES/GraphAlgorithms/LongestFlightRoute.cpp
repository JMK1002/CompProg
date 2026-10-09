//
// Created by JMKov on 12/5/2023.
//
#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> connections[100005];
set<int> radj[100005];
vector<int> top;
int explored[100005];
pair<int, int> dp[100005];

bool dfs(int v) {
    explored[v] = max(explored[v], 1);
    bool works = true;
    for (int adj : connections[v]) {
        if (explored[adj] == 1) return false;
        if (explored[adj] == 2) continue;
        works = works && dfs(adj);
    }
    if (explored[v] == 1) top.push_back(v);
    explored[v] = 2;
    return works;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        connections[a].insert(b);
        radj[b].insert(a);
    }
    bool works = true;
    for (int i = 0; i < n; i++) if (explored[i] != 2) works = works && dfs(i);
    if (!works) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) if (explored[i] != 2) top.push_back(i);

    for (int i = 0; i < n / 2; i++) {
        int a = top[i];
        top[i] = top[n - i - 1];
        top[n - i - 1] = a;
    }

    int inv[n];

    for (int i = 0; i < n; i++) inv[top[i]] = i;

    for (int i = inv[0]; i < n; i++) {
        for (int edge : radj[top[i]]) {
            if (dp[inv[edge]].first + 1 > dp[i].first) {
                dp[i].first = dp[inv[edge]].first + 1;
                dp[i].second = inv[edge];
            }
        }
    }
//    for (int i = 0; i < n; i++) cout << top[i] << endl;
//    cout << endl;
//    for (int i = 0; i < n; i++) cout << dp[i].first << " " << dp[i].second << endl;
    vector<int> ans;
    int ptr = inv[n - 1];
    while (top[ptr] != 0) {
        ans.push_back(top[ptr]);
        ptr = dp[ptr].second;
    }
    ans.push_back(0);
    if (ans[ans.size() - 1] != 0 || ans[0] != n - 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    cout << dp[n - 1].first + 1 << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] + 1 << " ";
    }
    return 0;
}
//10 10
//5 10
//4 10
//8 7
//7 10
//4 9
//8 3
//2 7
//2 5
//1 4
//6 7