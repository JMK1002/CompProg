#include <iostream>
using namespace std;

int main() {
    int a[6];
    int b[10] = { 0 };
    bool alien = true;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    for (int i : a) {
        b[i]++;
    }
    for (int i = 0; i < 10; i++) {
        if (b[i] >= 4) {
            b[i] -= 4;
            alien = false;
            break;
        }
    }
    if (alien) {
        cout << "Alien" << endl;
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (b[i] == 2) {
            cout << "Elephant" << endl;
            return 0;
        }
    }
    cout << "Bear" << endl;
    return 0;
}