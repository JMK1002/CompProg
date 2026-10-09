//
// Created by JMKov on 7/17/2023.
//

#include <iostream>
#include <algorithm>

using namespace std;

long long phi(long long n) {
    long long result = n;
    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long a, m;
        cin >> a >> m;
        long long g = __gcd(a, m);
        m /= g;
        cout << phi(m) << endl;
    }
    return 0;
}