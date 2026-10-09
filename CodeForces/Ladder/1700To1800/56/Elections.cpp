//
// Created by JMKov on 6/29/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int cost[105];
int arr[105][105];

bool compare(int a, int b) {
    return cost[a] < cost[b];
}

vector<int> candidate(int n, int m, int cand) {
    int indicies[m];
    int totalDiff = 0; // positive means the opposition wont win
    for (int i = 0; i < m; i++) {
        cost[i] = arr[i][cand];
        indicies[i] = i;
        cost[i] -= arr[i][n - 1];
        totalDiff += cost[i];
    }
    if (totalDiff >= 0) {
        return *new vector<int>;
    }
    sort(indicies, indicies + m, compare);
    sort(cost, cost + m);
    vector<int> ans;
    for (int i = 0; totalDiff < 0 && i < m; i++) {
        totalDiff -= cost[i];
//        cout << totalDiff << endl;
        ans.push_back(indicies[i]);
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    vector<int> ans = candidate(n, m, 0);
    for (int i = 1; i < n - 1; i++) {
        vector<int> a = candidate(n, m, i);
//        for (int j : a) cout << j << " ";
//        cout << endl;
        if (a.size() < ans.size()) {
            ans = a;
        }
    }
    cout << ans.size() << endl;
    for (int i : ans) cout << i + 1 << " ";
    cout << endl;
    return 0;
}