#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int binVal = 0;
    for (int i = 0; i < s.length(); i++) {
        binVal += pow(2, i) * (s[s.length() - i - 1] == '7');
    }
    binVal += pow(2, s.length()) - 1;
    cout << binVal << endl;
    return 0;
}