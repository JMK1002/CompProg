#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    bool checked[27] = { false };
    string s;
    cin >> s;
    for (char c : s) {
        checked[c - 'a'] = true;
        if (c - 'a' != 0 && !checked[c - 'a' - 1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}