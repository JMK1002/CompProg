//
// Created by JMKov on 7/26/2023.
//
#include <iostream>
#include <vector>
using namespace std;

vector<int> nxt[1002];

int dfs(int v, int * dist) {
    if (dist[v] != -1) {
        return dist[v] + 1;
    }
    for (int i : nxt[v]) {
        dist[v] = max(dist[v], dfs(i, dist));
    }
    return dist[v] + 1;
}

int main() {
    int n, k;
    cin >> n >> k;
    int indicies[n][k];
    int arr[n][k];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[j][i];
            arr[j][i]--;
            indicies[arr[j][i]][i] = j;
        }
    }
    for (int i = 0; i < n; i++) {
        int pos = indicies[i][0] + 1;
        while (pos < n) {
            bool works = true;
            for (int j = 1; j < k; j++) {
                if (indicies[arr[pos][0]][j] < indicies[i][j]) {
                    works = false;
                    break;
                }
            }
            if (works) nxt[i].push_back(arr[pos][0]);
            pos++;
        }
        if (nxt[i].empty()) nxt[i].push_back(-1);
    }
    int dist[n];
    for (int i = 0; i < n; i++) {
        dist[i] = (nxt[i][0] == -1) ? 1 : -1;
    }
    for (int i = 0; i < n; i++) dfs(i, dist);
    int ans = 0;
    for (int i : dist) ans = max(ans, i);
    cout << ans << endl;
//    for (int i = 0; i < n; i++) cout << nxt[i] << " ";
//    cout << endl;
//    for (int i : dist) cout << i << " ";
//    cout << endl;
    return 0;
}
//5 4
//1 4 2 3 5
//1 5 2 3 4
//5 1 4 2 3
//1 2 5 4 3