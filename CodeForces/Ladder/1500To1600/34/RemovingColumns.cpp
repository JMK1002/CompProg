//
// Created by JMKov on 5/15/2023.
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    bool staticRow[n - 1];
    for (bool& b : staticRow) {
        b = false;
    }
    for (int j = 0; j < m; j++) {
        bool row[n - 1];
        bool valid = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i][j] > arr[i + 1][j] && !staticRow[i]) {
                ans++;
                valid = false;
                break;
            }
            else if (arr[i][j] == arr[i + 1][j]) {
                row[i] = false;
            }
            else {
                row[i] = true;
            }
        }
        if (valid) {
            for (int i = 0; i < n - 1; i++) {
                staticRow[i] |= row[i];
            }
        }
    }
    cout << ans << endl;
    return 0;
}