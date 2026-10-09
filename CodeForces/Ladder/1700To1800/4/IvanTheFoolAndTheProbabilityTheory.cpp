//
// Created by JMKov on 6/7/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    long long fib[max(n, m)];
    fib[0] = 1;
    if (max(n, m) > 1) fib[1] = 2;
    for (long long i = 2; i < max(n, m); i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= 1000000007;
    }
    cout << ((fib[n - 1] + fib[m - 1] - 1) % 1000000007) * 2 % 1000000007 << endl;
    return 0;
}