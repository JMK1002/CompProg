//
// Created by JMKov on 10/10/2023.
//
#include <iostream>
#include <queue>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    int explored[n][m];
    queue<int> q;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}