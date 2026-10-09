//
// Created by JMKov on 5/14/2023.
//
#include <iostream>
using namespace std;
long long power(long long x, long long y, long long p)
{
    long long res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
    // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}
int main() {
    int n, m;
    cin >> n >> m;
    cout << power((power(2, m, 1000000007) - 1), n, 1000000007) << endl;
    return 0;
}