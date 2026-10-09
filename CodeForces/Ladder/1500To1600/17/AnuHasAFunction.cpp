//
// Created by JMKov on 5/10/2023.
//
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int compute(int x, int y) {
    return (x | y) - y;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    int bits[32];
    for (int i = 0; i < 32; i++) bits[i] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        int count = 0;
        for (int v = arr[i]; v > 0; v = v >> 1) {
            bits[count] += (v & 1);
            count++;
        }
//        cout << endl;
    }
//    for (int i : bits) {
//        cout << i << " ";
//    }
//    cout << endl;
    int mx = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        int count = 0;
        int out = 0;
        for (int v = arr[i]; v > 0; v = v >> 1) {
//            cout << bits[count] << " " << (v & 1) << endl;
            if (bits[count] <= 1 && (v & 1) == 1) {
                out += pow(2, count);
            }
            count++;
        }
        if (out > mx) {
            mx = out;
            index = i;
        }
//        cout << out << endl;
    }
    cout << arr[index] << " ";
    for (int i = 0; i < n; i++) {
        if (index == i) {
            continue;
        }
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
// 11 4
// 11 0
// 11 6
// 6 0