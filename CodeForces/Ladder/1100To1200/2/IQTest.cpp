#include <iostream>
#include <string>
using namespace std;

int main() {
    string s[4];
    for (int i = 0; i < 4; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int count = (s[i][j] == '#') + (s[i + 1][j] == '#') + (s[i][j + 1] == '#') + (s[i + 1][j + 1] == '#');
            if (count == 2) {
                continue;
            }
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}