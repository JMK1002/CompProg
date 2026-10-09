#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int b, g;
    cin >> b >> g;
    cout << b + g - 1 << endl;

    for (int i = 0; i < b; i++) {
        cout << i + 1 << " " << 1 << endl;
    }
    for (int i = 1; i < g; i++) {
        cout << 1 << " " << i + 1 << endl;
    }
    return 0;
}