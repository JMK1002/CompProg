#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, d;
    string lilies;
    int pos = 0;
    int jumps = 0;
    cin >> n >> d >> lilies;
    n--;
    while (pos < n) {
        int prevPos = pos;
        for (int i = pos + d; i >= pos; i--) {
            if (lilies[i] == '1') {
                jumps++;
                pos = i;
                break;
            }
        }
        if (pos == prevPos) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << jumps << endl;
    return 0;
}