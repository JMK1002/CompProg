//
// Created by JMKov on 2/18/2024.
//
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        bool ans = true;
        int n;
        cin >> n;
        int arr[n];
        long long v = 0;
        for (int i = 0 ; i < n; i++) {
            cin >> arr[i];
            v += arr[i];
        }
        v /= n;
        reverse(arr, arr + n);
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > v) {
                ans = false;
                break;
            }
            arr[i + 1] -= (v - arr[i]);
        }
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}