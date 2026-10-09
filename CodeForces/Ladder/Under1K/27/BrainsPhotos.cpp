#include <iostream>
#include <string>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int colored = false;
    for (int i = 0; i < x * y; i++) {
        char c;
        cin >> c;
        if (c != 'B' && c != 'W' && c != 'G') {
            colored = true;
            cout << "#Color" << endl;
            i = x * y;
        }
    }
    if (!colored) {
        cout << "#Black&White" << endl;
    }
}