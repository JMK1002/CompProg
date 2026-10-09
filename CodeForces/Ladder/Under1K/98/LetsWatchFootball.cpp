#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max((a * c) / b - c + ((a * c) % b != 0), 0) << endl;
    return 0;
}