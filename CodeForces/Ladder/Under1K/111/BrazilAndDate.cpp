#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    long long a, b, s;
    cin >> a >> b >> s;
    a = abs(a);
    b = abs(b);
    cout << ((abs(a + b - s) % 2 == 0 && (a + b - s) <= 0) ? "Yes" : "No") << endl;
    return 0;
}