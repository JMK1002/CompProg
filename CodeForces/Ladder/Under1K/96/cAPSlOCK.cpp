#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string newCaps = "";
    if (s[0] > 'Z') {
        newCaps += s[0] - 32;
    }
    else {
        newCaps += s[0] + 32;
    }
    bool caps = true;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] > 'Z') {
            cout << s << endl;
            return 0;
        }
        newCaps += s[i] + 32;
    }
    cout << newCaps << endl;
    return 0;
}