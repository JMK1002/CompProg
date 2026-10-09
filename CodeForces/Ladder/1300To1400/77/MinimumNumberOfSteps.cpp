//
// Created by JMKov on 4/27/2023.
//
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long asdf = 0;
    long long b = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'b') {
            asdf++;
            asdf %= 1000000007;
            b++;
        }
        else {
            asdf *= 2;
            asdf %= 1000000007;
        }
    }
    cout << (asdf - b) << endl;
    return 0;
}