//
// Created by JMKov on 5/16/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    int arr[n][2];
    int v = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    v = arr[0][0];
    int ans = 2;
    for (int i = 1; i < n - 1; i++) {
        if (arr[i][0] - arr[i][1] > v) {
            ans++;
            v = arr[i][0];
        }
        else if (arr[i][0] + arr[i][1] < arr[i + 1][0]) {
            ans++;
            v = arr[i][0] + arr[i][1];
        }
        else {
            v = arr[i][0];
        }
    }
    cout << ans << endl;
    return 0;
}