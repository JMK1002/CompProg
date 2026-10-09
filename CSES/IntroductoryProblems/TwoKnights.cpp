//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    int l;
    cin >> l;
    for (long long n = 1; n <= l; n++) {
        cout << (n * n) * (n * n - 1) / 2 - ((n - 4) * (n - 4) * 8 + (n - 4) * 4 * 6 + (n - 4) * 4 * 4 + 48) / 2 << endl;
    }
    return 0;
}