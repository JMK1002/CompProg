#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (s == "0") {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            s.erase(i, 1);
            i--;
        }
    }
    cout << "1" << s << endl;
    return 0;
}