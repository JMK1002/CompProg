#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int sum = 0;
    int pointer = 0;
    for (int i = 0; i < s.length(); i++) {
        sum += min(abs(s[i] - 97 - pointer), 26 - abs(s[i] - 97 - pointer));
        pointer = s[i] - 97;
    }
    cout << sum << endl;
}