//
// Created by JMKov on 5/13/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    long long s = 0;
    if (n == 1) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s += arr[i];
    }
    for (int i = 0; i < n; i++) {
        if (arr[i] * 2 > s || s % 2 == 1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}