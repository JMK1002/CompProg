//
// Created by JMKov on 5/9/2023.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) { cin >> arr[i]; }
        sort(arr.begin(), arr.end());
        int medals[3] = {0, 0, 0};
        int ptr = 0;
        int lastVal = 0;
        for (int i = arr.size() - 1; (medals[0] + medals[1] + medals[2]) * 2 <= n && i > 0; i--) {
            medals[ptr]++;
            if ((medals[0] + medals[1] + medals[2]) * 2 > n) break;
            if (arr[i] != arr[i - 1]) {
                if (ptr == 0 || medals[0] < medals[ptr]) {
                    ptr = min(ptr + 1, 2);
                }
                lastVal = medals[2];
            }
        }

        medals[2] = lastVal;
        if (medals[2] == 0 || medals[0] >= medals[1] || medals[0] >= medals[2]) {
            cout << "0 0 0" << endl;
        }
        else {
            for (int i : medals) {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}