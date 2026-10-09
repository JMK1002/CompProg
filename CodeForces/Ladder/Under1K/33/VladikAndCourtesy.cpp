#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int count = 1;
    while (true) {
        a -= count * (count % 2 == 1);
        b -= count * (count % 2 == 0);
        if (a < 0) {
            cout << "Vladik" << endl;
            break;
        }
        if (b < 0) {
            cout << "Valera" << endl;
            break;
        }
        count++;
    }

    return 0;
}