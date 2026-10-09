#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;
    if (log2(m) < n) {
        cout << m << endl;
        return 0;
    }
    long long a = 1;
    for (long long i = 0; i < n; i++) {
        a *= 2;
    }
    cout << m % a << endl;
}