//
// Created by JMKov on 4/2/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    long long mn;
    long long c;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
//    mn = gcd(a[0], a[1]);
//    for (int i = 2; i < n; i++) {
//        mn = gcd(mn, a[i]);
//    }
    for (int i = 0; i < n; i++) {
        while ((a[i] & 1) == 0) {
            a[i] /= 2;
        }
        while (a[i] % 3 == 0) {
            a[i] /= 3;
        }

    }
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            cout << "No" << endl;
            return 0;
        }
    }
//    cout << mn << endl;
//    cout << c << endl;
    cout << "Yes" << endl;
    return 0;
}