#include <iostream>
using namespace std;

int main() {
    int t1, t2;
    int n, t, k, d;
    cin >> n >> t >> k >> d;
    t1 = (n / k + (n % k != 0)) * t;
    int cakes = -1 * k;
    int built = 0;
    t2 = 0;
    while (n > cakes) {
        if (t2 % t == 0) {
            cakes += k;
        }
        if (built && t2 % t == built % t) {
            cakes += k;
        }
        if (t2 == d) {
            built = t2;
        }
        if (n <= cakes) {
            break;
        }
        t2++;
    }
    if (t1 <= t2) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
    return 0;
}