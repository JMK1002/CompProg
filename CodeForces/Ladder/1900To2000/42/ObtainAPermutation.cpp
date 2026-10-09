//
// Created by JMKov on 8/5/2023.
//
#include <iostream>
using namespace std;

int n, m;

int minShift(int col, int arr[]) {
    int moves[n];
    for (int i = 0; i < n; i++) {
        moves[i] = i + n;
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] % m == col && (arr[i] - col) / m < n) {
            int p = i - (arr[i] - col) / m;
            if (p < 0) p += n;
            moves[p]--;
        }
    }
    int ret = INT32_MAX;
    for (int i = 0; i < n; i++) ret = min(ret, moves[i]);
    return ret;
}

int main() {
    cin >> n >> m;
    int arr[m][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[j][i];
            arr[j][i]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) {
//        cout << minShift(i, arr[i]) << endl;
        ans += minShift(i, arr[i]);
    }
    cout << ans << endl;
    return 0;
}