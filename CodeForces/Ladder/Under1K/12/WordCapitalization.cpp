#include <string>
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string a = "";
    a += toupper(s[0]);
    a += s.substr(1, s.length());
    cout << a << endl;
}