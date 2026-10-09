#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 2; i++) {
        int a;
        cin >> a;
    }
    int a, b;
    if (n == 1) {
        cin >> b;
        a = b;
    }
    else {
        cin >> a >> b;
    }
    if (b == 15 || (a > b && (a != 1 || b != 0))) {
        cout << "DOWN" << endl;
        return 0;
    }
    else if (b == 0 || b > a && (a != 14 || b != 15)) {
        cout << "UP" << endl;
        return 0;
    }
    else {
        cout << -1 << endl;
        return 0;
    }
    return 0;
}