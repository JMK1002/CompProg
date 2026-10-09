#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int sum = a + b + c + n;
        bool distributable = (sum % 3 == 0) && (n >= (3 * max(max(a, b), c) - a - b - c));
        cout << (distributable ? "YES" : "NO") << endl;
    }
    return 0;
}