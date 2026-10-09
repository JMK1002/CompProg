//
// Created by JMKov on 5/26/2024.
//
#include <iostream>
#include <vector>

using namespace std;

int arr[40];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        int cnt = 0;
        while (x != 0) {
            arr[cnt] = (x & 1);
            x >>= 1;
            cnt++;
        }
        for (int i = 0; i < 34; i++) {
            if (arr[i] == 1 && arr[i] == arr[i + 1]) {
                cnt = i;
                while (arr[cnt] == 1) {
                    arr[cnt] = 0;
                    cnt++;
                }
                arr[i] = -1;
                arr[cnt] = 1;
            }
        }
        cout << 32 << endl;
        for (int i = 0; i < 32; i++) cout << arr[i] << " ";
        cout << endl;
        for (int i = 0; i < 40; i++) {
            arr[i] = 0;
        }
    }
    return 0;
}