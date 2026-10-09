#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    bool a = false, b = false, e = false, d = false;
    a = s.length() >= 5;
    for (char c : s) {
        if (c <= 'Z' && c >= 'A') {
            d = true;
        }
        else if (c <= 'z' && c >= 'a') {
            e = true;
        }
        else if ((c - 48 < 10 && c - 48 > -1)) {
            b = true;
        }
    }
    cout << (a && b && e && d ? "Correct" : "Too weak") << endl;
}