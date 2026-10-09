//
// Created by JMKov on 4/12/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] == arr[i + 1]) {
                arr.erase(arr.begin() + i);
//                cout << i << " ";
                i--;
            }
        }
//        cout << endl;
        int ans = 0;
//        for (int i = 0; i < arr.size(); i++) {
//            cout << arr[i] << endl;
//        }
        while (arr.size() != 0) {
            ans++;
            arr.erase(arr.end() - 1);
            while (arr[0] <= r * ans && arr.size() > 0) {
                arr.erase(arr.begin());
            }
        }
        cout << ans << endl;
    }
    return 0;
}