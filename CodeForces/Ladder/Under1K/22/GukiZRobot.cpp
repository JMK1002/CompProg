#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << max(abs(c - a), abs(d - b)) << endl;
}