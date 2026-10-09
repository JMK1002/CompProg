#include <iostream>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    int num[n] = { 0 };
    num[0] = t;
    if (t == 10 && n == 1) {
        cout << -1 << endl;
        return 0;
    }
    if (t == 10 && n == 2) {
        cout << 10 << endl;
        return 0;
    }
    while (true) {
        if (num[n - 1] != 0) {
            for (int i = n - 1; i >= 0; i--) {
                cout << num[i];
            }
            break;
        }
        for (int i = n - 1; i >= 0; i--) {
            num[i] *= t;
        }
        for (int i = 0; i < n - 1; i++) {
            num[i + 1] += num[i] / 10;
            num[i] %= 10;
        }
    }
    return 0;
}