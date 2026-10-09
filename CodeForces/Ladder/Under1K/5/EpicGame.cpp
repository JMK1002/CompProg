#include <string>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    else {
        return gcd(b, a % b);
    }
}

int main() {
    int a, b, n;
    cin >> a >> b >> n;
    while (true) {
        if (gcd(a, n) > n) {
            cout << 1 << endl;
            break;
        }
        n -= gcd(a, n);
        if (gcd(b, n) > n) {
            cout << 0 << endl;
            break;
        }
        n -= gcd(b, n);
    }
}