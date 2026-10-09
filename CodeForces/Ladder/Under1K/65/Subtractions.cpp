#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int count = 0;
        while (min(a, b) != 0) {
            count += max(a, b) / min(a, b);
            if (a > b) {
                a %= b;
            }
            else {
                b %= a;
            }
        }
        cout << count << endl;
    }
    return 0;
}