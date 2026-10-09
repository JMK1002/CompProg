//
// Created by JMKov on 4/26/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n][n];
    long long rSum[n];
    long long cSum[n];
    pair<int, int> empty;
    for (int i = 0; i < n; i++) {
        rSum[i] = 0;
        cSum[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            rSum[i] += arr[i][j];
            cSum[j] += arr[i][j];
            if (arr[i][j] == 0) {
                empty.first = i;
                empty.second = j;
            }
        }
    }
    long long mv = rSum[(0 == empty.first)];
    arr[empty.first][empty.second] = mv - rSum[empty.first];
    rSum[empty.first] += arr[empty.first][empty.second];
    cSum[empty.second] += arr[empty.first][empty.second];
    if (arr[empty.first][empty.second] <= 0) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (mv != rSum[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (mv != cSum[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[i][i];
    }
    if (s != mv) {
        cout << -1 << endl;
        return 0;
    }
    s = 0;
    for (int i = 0; i < n; i++) {
        s += arr[n - i - 1][i];
    }
    if (s != mv) {
        cout << -1 << endl;
        return 0;
    }
    cout << arr[empty.first][empty.second] << endl;
    return 0;
}