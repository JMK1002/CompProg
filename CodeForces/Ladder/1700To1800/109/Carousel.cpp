//
// Created by JMKov on 7/18/2023.
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
        bool same = true;
        bool twoCons = false;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (same && i != 0 && arr[i] != arr[i - 1]) same = false;
            if (!twoCons && i != 0 && arr[i] == arr[i - 1]) twoCons = true;
        }
        if (same) {
            cout << 1 << endl;
            for (int i = 0; i < n; i++) cout << 1 << " ";
            cout << endl;
            continue;
        }
        if ((n & 1) == 0) {
            cout << 2 << endl;
            for (int i = 0; i < n; i++) cout << (i & 1) + 1 << " ";
            cout << endl;
            continue;
        }
        if ((n & 1) && twoCons || arr[0] == arr[n - 1]) {
            cout << 2 << endl;
            for (int i = 0; i < n; i++) {
                if (i != 0 && arr[i] == arr[i - 1]) twoCons = false;
                cout << ((twoCons) ^ (i & 1)) + 1 << " ";
            }
            cout << endl;
            continue;
        }
        else {
            cout << 3 << endl;
            for (int i = 0; i < n; i++) {
                if (i == n - 1) cout << 3 << " ";
                else cout << (i & 1) + 1 << " ";
            }
            cout << endl;
            continue;
        }
//        cout << (((n & 1) && arr[n - 1] != arr[0] && arr[n - 1] != arr[n - 2]) ? 3 : 2) << endl;
//        for (int i = 0; i < n; i++) {
//            if (i == n - 1 && ((n & 1) && arr[n - 1] != arr[0] && arr[n - 1] != arr[n - 2])) cout << 3 << " ";
//            else {
//                cout << (i & 1) + 1 << " ";
//            }
//        }
//        cout << endl;
    }
    return 0;
}