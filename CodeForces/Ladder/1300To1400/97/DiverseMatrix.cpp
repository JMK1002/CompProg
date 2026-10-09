//
// Created by JMKov on 5/4/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    if (r == 1 && c == 1) {
        cout << 0 << endl;
        return 0;
    }
    bool swapped = false;
    if (r > c) {
        int a = c;
        c = r;
        r = a;
        swapped = true;
    }
    // r < c
    int arr[r][c];
    arr[0][0] = 2;
    for (int i = 0; i < r; i++) {
        arr[i][0] = (i + 1) * 2;
    }
    for (int i = 1; i < r; i++) {
        arr[0][i] = (i + 1) * 2 - 1;
    }
    for (int i = r; i < c; i++) {
        arr[0][i] = r + i + 1;
    }
    // end of assignment
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            arr[i][j] = arr[i][0] / __gcd(arr[i][0], arr[0][j]) * arr[0][j];
        }
    }
    if (swapped) {
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                cout << arr[j][i] << " ";
            }
            cout << endl;
        }
    }
    else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}