//
// Created by JMKov on 5/18/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i] = abs(arr[i]);
    }
    sort(arr.begin(), arr.end());
    for (int i : arr) {
        int v = distance(lower_bound(arr.begin(), arr.end(), i - i / 2), upper_bound(arr.begin(), arr.end(), i * 2));
        v -= 1;
        v = max(v, 0);
        ans += v;
//        cout << v << " " << i << endl;
    }
    cout << ans / 2 << endl;
    return 0;
}