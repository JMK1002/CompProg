//
// Created by JMKov on 4/13/2023.
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
        int pos[n + 1];
        bool explored[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            pos[arr[i] - 1] = i;
        }
        int leftPtr = pos[0];
        int rightPtr = pos[0];
        for (int i = 0; i < n; i++) {
            explored[i] = false;
        }
        for (int i = 0; i < n; i++) {
            explored[pos[i]] = true;
            while (leftPtr + 1 < n && explored[leftPtr + 1]) {
                leftPtr++;
            }
            while (rightPtr - 1 >= 0 && explored[rightPtr - 1]) {
                rightPtr--;
            }
//            cout << leftPtr << " " << rightPtr << endl;
            cout << (leftPtr - rightPtr == i);
        }
        cout << endl;
    }
    return 0;
}