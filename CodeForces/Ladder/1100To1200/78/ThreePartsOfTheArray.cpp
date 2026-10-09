//
// Created by JMKov on 3/31/2023.
//
#include <iostream>
using namespace std;

int binSearch(long long array[], long long target, int mn, int mx) {
    if (mn > mx) {
        return -1;
    }
    int mid = (mx + mn) / 2;
    if (array[mid] == target) {
        return mid;
    }
    else if (array[mid] < target) {
        return binSearch(array, target, mn, mid - 1);
    }
    else {
        return binSearch(array, target, mid + 1, mx);
    }
}

int main() {
    int n;
    cin >> n;
    long long prefix[n + 1];
    long long inversePrefix[n + 1];
    int a[n];
    prefix[0] = 0;
    inversePrefix[n] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i + 1] = prefix[i] + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        inversePrefix[i] = inversePrefix[i + 1] + a[i];
    }
    for (int i = n + 1; i >= 0; i--) {
        if (binSearch(inversePrefix, prefix[i], i, n + 1) > 0) {
            cout << prefix[i] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}