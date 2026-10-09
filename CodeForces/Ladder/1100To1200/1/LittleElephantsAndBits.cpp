#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    bool changed = false;
    cin >> s;
    for (int i = 0; i < s.length() && !changed; i++) {
        if (s[i] == '0') {
            s.erase(s.begin() + i);
            changed = true;
        }
    }
    if (!changed) {
        s.erase(s.begin());
    }
    cout << s << endl;

    return 0;
}