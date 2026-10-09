#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int total = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        total += a;
    }
    int count = 0;
    for (int i = 1; i < 6; i++) {
        if ((total + i) % (n + 1) == 1) {
            count++;
        }
    }
    cout << (5 - count) << endl;
    return 0;
}