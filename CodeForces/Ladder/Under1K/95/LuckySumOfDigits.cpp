#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string num = "";
    while (n > 0) {
        if (n % 7 == 0) {
            num += "7";
            n -= 7;
        }
        else {
            num += '4';
            n -= 4;
        }
    }
    if (n < 0) {
        cout << -1 << endl;
    }
    else {
        cout << num << endl;
    }
}