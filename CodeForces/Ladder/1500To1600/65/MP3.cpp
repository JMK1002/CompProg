//
// Created by JMKov on 5/25/2023.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    k *= 8;
    k /= n;
    k = pow(2, min(30, k));
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    vector<int> borders;
    for (int i : borders) cout << i << " ";
    borders.push_back(0);
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            borders.push_back(i);
        }
    }
    borders.push_back(n);
    int ans = 0;
    if (0 >= (long long) borders.size() - k) {
        cout << 0 << endl;
        return 0;
    }
//    for (int i : borders) cout << i << " ";
    for (int i = 0; i < borders.size() - k; i++) {
        ans = max(ans, borders[i + k] - borders[i]);
    }
    cout << n - ans << endl;
    return 0;
}