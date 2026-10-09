//
// Created by JMKov on 5/1/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    vector<int> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans += arr[i] / 10;
        v[i] = 10 - arr[i] % 10;
    }
    sort(v.begin(), v.end());
    int ptr = 0;
    while (k >= 0 && ptr != v.size()) {
        k -= v[ptr];
        ptr++;
    }
    if (k < 0) {
        k += v[ptr - 1];
        ans += ptr - 1;
    }
    else {
        ans += ptr;
        ans += k / 10; // max of 100 might make this not work
    }
    cout << min(n * 10, ans) << endl;
    return 0;
}