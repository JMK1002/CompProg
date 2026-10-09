//
// Created by JMKov on 5/22/2023.
//
#include <iostream>
using namespace std;

int main() {
    int arr[6];
    for (int i = 0; i < 6; i++) {
        cin >> arr[i];
    }
    int x = arr[0] + arr[1] + arr[2];
    cout << x * x - arr[0] * arr[0] - arr[2] * arr[2] - arr[4] * arr[4] << endl;
    return 0;
}