#include <string>
#include <iostream>
using namespace std;

int main() {
    string n;
    cin >> n;
    bool chars[26] = { false };
    int i = 0;
    for (char c : n) {
        i += !chars[c - 'a'];
        chars[c - 'a'] = true;
    }

    cout << ((i % 2) ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
}