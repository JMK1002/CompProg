//
// Created by JMKov on 5/15/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int mx = 0;
        int mnX = 2000000000;
        int mxX = -1;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == -1 && arr[i + 1] == -1) mx = max(0, mx);
            else if (arr[i] == -1) {
                mnX = min(mnX, arr[i + 1]);
                mxX = max(mxX, arr[i + 1]);
            }
            else if (arr[i + 1] == -1) {
                mnX = min(mnX, arr[i]);
                mxX = max(mxX, arr[i]);
            }
            else {
                mx = max(mx, abs(arr[i] - arr[i + 1]));
            }
        }
        if (mnX == 2000000000) {
            cout << mx << " " << 0 << endl;
            continue;
        }
        int midpoint = (mxX + mnX) / 2;
        cout << max(mx, max(abs(mnX - midpoint), abs(mxX - midpoint))) << " " << midpoint << endl;
    }
    return 0;
}