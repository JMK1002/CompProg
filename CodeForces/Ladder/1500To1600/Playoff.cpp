//
// Created by JMKov on 6/16/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int zero = 0;
    for (char c : s) {
        zero += c == '0';
    }
    int l = (1 << (n - zero));
    int r = (1 << n) - ((1 << (zero)) - 1);
//    cout << l << " " << r << endl;
    for (int i = l; i <= r; i++) {
        cout << i << " ";
    }
    return 0;
}