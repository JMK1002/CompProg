//
// Created by JMKov on 4/19/2023.
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
    int ans = 0;
    while (!arr.empty()) {
        int count = 1;
        arr.erase(arr.begin());
        for (int i = 0; i < arr.size(); i++) {
            if (count < (arr[i] + 1)) {
                arr.erase(arr.begin() + i);
                i--;
                count++;
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}