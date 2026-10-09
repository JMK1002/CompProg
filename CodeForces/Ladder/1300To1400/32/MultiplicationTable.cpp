//
// Created by JMKov on 4/12/2023.
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long arr[n][n];
    int ans[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    ans[0] = sqrt(arr[0][1] * arr[0][2] / arr[1][2]);
    cout << ans[0] << " ";
    for (int i = 1; i < n; i++) {
        cout << arr[i][0] / ans[0] << " ";
    }
    return 0;
}