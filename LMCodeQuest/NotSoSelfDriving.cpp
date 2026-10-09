//
// Created by JMKov on 4/18/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        double v, x;
        char a; // stores the :
        cin >> v >> a >> x;
        if (v >= x) {
            cout << "SWERVE" << endl;
        }
        else if (v * 5 >= x) {
            cout << "BRAKE" << endl;
        }
        else {
            cout << "SAFE" << endl;
        }
    }
    return 0;
}