//
// Created by JMKov on 4/6/2023.
//
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    for (long long i = 2; pow(i, 2) <= n; i++) {
        if (n % (long long) pow(i, 2) == 0) {
            n /= i;
            i--;
        }
    }
    cout << n << endl;
    return 0;
}