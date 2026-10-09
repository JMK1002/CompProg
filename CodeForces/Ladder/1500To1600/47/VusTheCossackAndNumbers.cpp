//
// Created by JMKov on 5/19/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double arr[n];
    long long sum = 0;
    bool ints[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ints[i] = false;
        if (floor(arr[i]) == ceil(arr[i])) ints[i] = true;
        sum += floor(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (sum != 0 && !ints[i]) {
            cout << floor(arr[i]) + 1 << endl;
            sum++;
        }
        else {
            cout << floor(arr[i]) << endl;
        }
    }
    return 0;
}