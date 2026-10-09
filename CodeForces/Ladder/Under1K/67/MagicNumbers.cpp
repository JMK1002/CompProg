#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int fc;
    if (s[0] != '1') {
        cout << "NO" << endl;
        return 0;
    }
    for (char c : s) {
        if (c == '1') {
            fc = 0;
        }
        else if (c == '4') {
            fc++;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
        if (fc > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}