//
// Created by JMKov on 5/16/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    cout << n << " " << n + 1 << " " << (n + 1) * (n) << endl;
    return 0;
}