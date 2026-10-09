#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int as = 0;
        int bs = 0;
        a -= 1;
        as = ((a + 1) / 2) * pow(-1, a);
        bs = ((b + 1) / 2) * pow(-1, b);
        cout << bs - as << endl;
    }
    return 0;
}