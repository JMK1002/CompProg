#include <iostream>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        long long n;
        cin >> n;
        int ret = 0;
        while (n % 2 == 0) {
            n /= 2;
            ret++;
        }

        while (n % 3 == 0) {
            n /= 3;
            ret += 2;
        }

        while (n % 5 == 0) {
            n /= 5;
            ret += 3;
        }

        if (n != 1) {
            cout << -1 << endl;
            continue;
        }
        cout << ret << endl;
    }
}