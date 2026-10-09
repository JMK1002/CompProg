//
// Created by JMKov on 4/28/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> arr(n);
    vector<int> dist(n - 1); // n might be one

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i < n; i++) {
        dist[i - 1] = arr[i] - arr[i - 1] - 1;
    }
    int ans = arr[n - 1] - arr[0] + 1;
    sort(dist.begin(), dist.end());
    for (int i = n - 2; i >= n - k; i--) {
        ans -= dist[i];
    }
    cout << ans << endl;
    return 0;
}