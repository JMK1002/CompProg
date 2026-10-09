//
// Created by JMKov on 4/13/2023.
//
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long prefix[n];
        int arr[n];
        cin >> arr[0];
        prefix[0] = arr[0];
        long long low = min((long long) 0, prefix[0]);
        int lowPtr = (low == 0) ? -1 : 0;
        int highPtr = -1000000000;
        long long mx = prefix[0] - low;
        for (int i = 1; i < n; i++) {
            cin >> arr[i];
            prefix[i] = prefix[i - 1] + arr[i];
        }
        for (int i = 1; i < n; i++) {
            if (prefix[i] <= low) {
                low = prefix[i];
                lowPtr = i;
            }
            if (prefix[i] - low > mx) {
                mx = prefix[i] - low;
                highPtr = i;
            }
        }
//        cout << prefix[n - 1] << " " << lowPtr << " " << highPtr << " " << mx << " " << low << endl;
        if ((lowPtr == -1 && highPtr == n - 1) || prefix[n - 1] > mx) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}