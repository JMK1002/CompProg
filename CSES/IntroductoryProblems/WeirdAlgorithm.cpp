//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    istream::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n /= 2;
        }
        else {
            n *= 3;
            n += 1;
        }
    }
    cout << 1 << " ";
    return 0;
}