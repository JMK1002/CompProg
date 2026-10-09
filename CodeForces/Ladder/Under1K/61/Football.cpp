#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    for (char c : s) {
        if (c == '0') {
            count = (count < 0) * count - 1;
        }
        else {
            count = (count > 0) * count + 1;
        }
        if (abs(count) == 7) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}