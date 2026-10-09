#include <iostream>
#include <math.h>
#include <string>
using namespace std;

string correct(string s) {
    bool prevChar = false;
    for (int i = 0; i < s.length(); i++) {
        bool vowel = (s[i] == 'a' || s[i] == 'e' || s[i] == 'u' || s[i] == 'o' || s[i] == 'i' || s[i] == 'y');
        if (vowel && prevChar) {
            s.replace(i, 1, "");
            i -= 2;
            prevChar = false;
        }
        else if (vowel) {
            prevChar = true;
        }
        else {
            prevChar = false;
        }
    }
    return s;
}
int main () {
    int n;
    string s;
    cin >> n >> s;
    cout << correct(s) << endl;;
    return 0;
}