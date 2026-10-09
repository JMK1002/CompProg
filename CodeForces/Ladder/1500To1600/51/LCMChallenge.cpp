//
// Created by JMKov on 5/21/2023.
//
#include <iostream>
#include <algorithm>
using namespace std;

long long lcm(long long a, long long b) {
    return a * b / __gcd(a, b);
}

int main() {
    long long n;
    cin >> n;
//    if (n < 3) {
//        cout << n << endl;
//        return 0;
//    }
//    else if (n < 5) {
//        cout << (n - 1) * (n) << endl;
//        return 0;
//    }
    cout << max(max(n, lcm(lcm(n, n - 1), n - 3)), max(max(lcm(n - 1, n - 2), lcm(n, n - 1)), max(lcm(lcm(n, n - 1), n - 2), lcm(lcm(n - 3, n - 1), n - 2)))) << endl;
    return 0;
}