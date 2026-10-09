#include <iostream>
using namespace std;

int main (){
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << a << endl;
    }
    else if (b - a == 1) {
        cout << 2 << endl;
    }
    else if (a % 3 == 0 && b % 3 == 0 && b - a < 4) {
        cout << 3 << endl;
    }
    else {
        cout << 2 << endl;
    }
    return 0;
}