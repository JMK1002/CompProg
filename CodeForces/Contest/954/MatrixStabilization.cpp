//
// Created by JMKov on 6/23/2024.
//
#include <iostream>
#include <set>
using namespace std;

int n, m;
int arr[102][102];

int findMax(pair<int, int> ind) {
    int i = ind.first;
    int j = ind.second;
    int ans = 1;
    if (i != 0) ans = max(ans, arr[i - 1][j]);
    if (i != n - 1) ans = max(ans, arr[i + 1][j]);
    if (j != 0) ans = max(ans, arr[i][j - 1]);
    if (j != m - 1) ans = max(ans, arr[i][j + 1]);
    return ans;
}

void findCells() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            bool works = true;
            if (i != 0) works = works && (arr[i][j] > arr[i - 1][j]);
            if (i != n - 1) works = works && (arr[i][j] > arr[i + 1][j]);
            if (j != 0) works = works && (arr[i][j] > arr[i][j - 1]);
            if (j != m - 1) works = works && (arr[i][j] > arr[i][j + 1]);
            if (works) arr[i][j] = findMax({i, j});
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    findCells();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
            arr[i][j] = 0;
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}