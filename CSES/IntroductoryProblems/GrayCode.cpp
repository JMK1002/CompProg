//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    string arr[(1 << (n))];
    arr[0] = "";
    int l = 1;
    while (l <= n) {
        for (int i = (1 << (l - 1)); i < (1 << l); i++) {
            arr[i] = arr[(1 << l) - 1 - i];
        }
        for (int i = 0; i < (1 << (l - 1)); i++) {
            arr[i] = "0" + arr[i];
        }
        for (int i = 1 << (l - 1); i < (1 << l); i++) {
            arr[i] = "1" + arr[i];
        }
        l++;
    }
    for (string s : arr) cout << s << endl;
    return 0;

}