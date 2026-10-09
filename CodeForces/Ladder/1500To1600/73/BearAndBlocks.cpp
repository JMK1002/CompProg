//
// Created by JMKov on 5/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n + 2];
    arr[0] = 0;
    arr[n + 1] = 0;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int v = 0;
    for (int i = 0; i < n + 2; i++) {
        arr[i] = min(arr[i], v);
        v = arr[i];
        v++;
    }
    v = 0;
    for (int i = n + 1; i >= 0; i--) {
        arr[i] = min(arr[i], v);
        v = arr[i];
        v++;
    }
    int ans = 0;
    for (int i = 0; i < n + 2; i++) {
        ans = max(ans, arr[i]);
    }
    cout << ans << endl;
    return 0;
}