//
// Created by JMKov on 3/28/2023.
//
#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int ans[k - 1];
        int totSum = 0;
        int currSum = 0;
        int ansIndex = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            currSum += a;
            totSum += a;
            if ((currSum & 1) == 1 && ansIndex != k - 1) {
                currSum = 0;
                ans[ansIndex] = i + 1;
                ansIndex++;
            }
        }
        if ((k & 1) != (totSum & 1) || (currSum & 1) != 1) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
            for (int i : ans) {
                cout << i << " ";
            }
            cout << n << endl;
        }
    }
    return 0;
}