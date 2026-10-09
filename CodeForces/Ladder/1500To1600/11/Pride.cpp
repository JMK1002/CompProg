//
// Created by JMKov on 5/8/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int oneCount = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        oneCount += arr[i] == 1;
//        arr[i] = (i + 1) * 6;
    }
//    arr[0] = 3;
//    arr[n - 1] = 2;
    if (oneCount != 0) {
        cout << n - oneCount << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            arr[j] = __gcd(arr[j], arr[j + 1]);
            if (arr[j] == 1) {
                cout << n + i << endl;
//                cout << j << endl;
                return 0;
            }
        }
//        for (int x : arr) {
//            cout << x << " ";
//        }
//        cout << endl;
    }
    cout << -1 << endl;
    return 0;
}