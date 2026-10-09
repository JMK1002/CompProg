#include <iostream>
#include <math.h>
using namespace std;

int main() {
    long long x, y, a, b ,c;
    long long asdf = 0;
    cin >> x >> y >> a >> b >> c;
    cout << max(asdf, a * 2 + b - x) + max(asdf, c * 3 + b - y) << endl;
    return 0;
}