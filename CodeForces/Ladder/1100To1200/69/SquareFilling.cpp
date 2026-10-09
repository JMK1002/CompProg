//
// Created by JMKov on 3/28/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    bool hasSolution = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    int count = 0;
    vector<pair<int, int>> ans(0);
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (matrix[i][j] && matrix[i + 1][j] && matrix[i][j + 1] && matrix[i + 1][j + 1]) {
                matrix[i + 1][j] = 2;
                matrix[i][j + 1] = 2;
                matrix[i + 1][j + 1] = 2;
                matrix[i][j] = 2;
                count++;
                pair<int, int> location = {i, j};
                ans.insert(ans.end(), location);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    cout << count << endl;
    for (pair<int, int> a : ans) {
        cout << a.first + 1 << " " << a.second + 1 << endl;
    }
    return 0;
}