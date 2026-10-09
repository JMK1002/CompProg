#include <iostream>
using namespace std;

string getExpression(int v, bool rev) {
    if (v < 0 && rev) {
        return "+" + abs(v / 2) + "-" + abs(v / 2);
    }
}

int main() {
    int p, q;
    cin >> p >> q;

    return 0;
}