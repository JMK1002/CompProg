//
// Created by JMKov on 5/13/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int ans[n];
    int mx = -1;
    int index = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ans[i] = (abs(arr[i] * -1 - 1) > abs(arr[i])) ? arr[i] * -1 - 1 : arr[i];
        if (ans[i] * -1 - 1 > mx) {
            mx = ans[i] * -1 - 1;
            index = i;
        }
    }
    if (n % 2 == 1) {
        ans[index] = ans[index] * -1 - 1;
    }
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}