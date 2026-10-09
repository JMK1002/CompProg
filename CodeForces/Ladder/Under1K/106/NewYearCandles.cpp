#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int wentOut = 0;
    int hrs = 0;
    while (a > 0) {
        hrs += a;
        wentOut += a;
        a = 0;
        a += wentOut / b;
        wentOut %= b;
    }
    cout << hrs << endl;
    return 0;
}