//
// Created by JMKov on 4/18/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int prev = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (prev <= arr[i]) {
            ans++;
            prev += arr[i];
        }
    }
    cout << ans << endl;
    return 0;
}