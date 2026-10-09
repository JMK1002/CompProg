#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, l;
    cin >> s >> l;
    bool t = false;
    string p = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != l[i]) {
            p += t ? s[i] : l[i];
            t = !t;
        }
        else {
            p += s[i];
        }
    }
    if (!t) {
        cout << p << endl;
    }
    else {
        cout << "impossible" << endl;
    }
    return 0;
}