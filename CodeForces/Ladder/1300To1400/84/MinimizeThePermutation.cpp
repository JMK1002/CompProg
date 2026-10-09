//
// Created by JMKov on 4/29/2023.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        bool swaps[n];
        int indices[n];
        int a = 0;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i]--;
            indices[arr[i]] = i;
            swaps[i] = false;
        }
        // 5 4 1 3 2
        //
        for (int i = 0; i < n; i++) {
            while (indices[i] != 0 && i < arr[indices[i] - 1] && !swaps[indices[i]]) {
                swaps[indices[i]] = true;
                arr[indices[i]] = arr[indices[i] - 1];
                arr[indices[i] - 1] = i;
                indices[arr[indices[i]]]++;
                indices[i]--;
            }
//            for (int x : indices) {
//                cout << x << " ";
//            }
//            cout << endl;
        }
        for (int i : arr) {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}