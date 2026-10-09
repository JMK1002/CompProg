#include <iostream>
#include <string>
using namespace std;

bool symmetric(char c) {
    char a[11] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
    for (char ab : a) {
        if (ab == c) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    for (int i = 0; i < s.length() / 2 + 1; i++) {
        if (s[i] != s[s.length() - i - 1] || !symmetric(s[i])) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}