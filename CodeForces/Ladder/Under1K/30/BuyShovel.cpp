#include <iostream>
using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    for (int i = 1; i < 10; i++) {
        if (n == (i * k) % 10 || (k * i) % 10 == 0) {
            cout << i << endl;
            i = 10;
        }
    }
    return 0;
}