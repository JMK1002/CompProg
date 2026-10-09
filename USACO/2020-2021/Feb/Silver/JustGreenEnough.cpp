//
// Created by JMKov on 8/21/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    int pre[n][n];
    pre[0][0] = (arr[0][0] < 100);
    for (int i = 1; i < n; i++) {
        pre[0][i] = pre[0][i - 1] + (arr[0][i] < 100);
        pre[i][0] = pre[i - 1][0] + (arr[i][0] < 100);
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pre[j][i] = pre[j - 1][i] + pre[j][i - 1] - pre[j - 1][i - 1] + (arr[j][i] < 100);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << pre[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}