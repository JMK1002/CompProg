//
// Created by JMKov on 6/2/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double r, x1, y1, x2, y2;
    cin >> r >> x1 >> y1 >> x2 >> y2;
    cout.precision(10);
    if (pow(x2 - x1, 2) + pow(y2 - y1, 2) >= r * r) {
        cout << x1 << " " << y1 << " " << r << endl;
        return 0;
    }
    if (x2 == x1) {
        if (y1 + r - y2 > y2 - y1 + r) {
            cout << x1 << " " << (y1 + r + y2) / 2 << " " << (y1 + r - y2) / 2 << endl;
        }
        else {
            cout << x1 << " " << (y1 - r + y2) / 2 << " " << (r - y1 + y2) / 2 << endl;
        }
        return 0;
    }
    double m = (y2 - y1) / (x2 - x1); // division by zero?
    double tanX = x1 + r / sqrt(m * m + 1);
    double tanY = y1 + r * m / sqrt(m * m + 1);
//    cout << tanX << " " << tanY << endl;
    if ((x2 - x1 < 0 && tanX - x1 < 0) || (x2 - x1 > 0 && tanX - x1 > 0)) tanX = (tanX - x1) * -1 + x1;
    if ((y2 - y1 < 0 && tanY - y1 < 0) || (y2 - y1 > 0 && tanY - y1 > 0)) tanY = (tanY - y1) * -1 + y1;

    double diamater = sqrt(pow(tanX - x2, 2) + pow(tanY - y2, 2)) ;
//    cout << tanX << " " << tanY << " " << diamater << endl;
    cout << (tanX + x2) / 2 << " " << (tanY + y2) / 2 << " " << diamater / 2 << endl;
    return 0;
}

//(m^2+1)(x-x1)^2 = r^2    (y-y1)^2 = m^2(x - x1)^2
// x - x1 = r/sqrt(m^2+1)
// x = x1 + r/sqrt(m^2+1)
// y = y1 + rm/sqrt(m^2+1))

// 100000 0 0 90000 0
//            100000 0