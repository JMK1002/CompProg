//
// Created by JMKov on 3/26/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int rotations[n];
    for (int i = 0; i < n; i++) {
        cin >> rotations[i];
    }
    for (int i = 0; i < (2 << n); i++) {
        int amnt = 0;
        for (int j = 0 ; j < n; j++) {
            amnt += rotations[j] * (((i >> j) & 1) == 1 ? 1 : -1);
        }
        if (amnt % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}