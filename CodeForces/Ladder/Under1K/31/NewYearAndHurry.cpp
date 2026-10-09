#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int prevTime = 0;
    for (int i = 1; i <= n; i++) {
        prevTime += i * 5;
        if (prevTime + k > 240) {
            cout << i - 1 << endl;
            break;
        }
    }
    if (5 * n * (n + 1) + 2 * k <= 480) {
        cout << n << endl;
    }
}