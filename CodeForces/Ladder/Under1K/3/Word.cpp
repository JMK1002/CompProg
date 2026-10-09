#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    string a, u = "", l = "";
    cin >> a;
    int lc = 0, uc = 0;
    for (char c : a) {
        u += toupper(c);
        l += tolower(c);
        if (c < 'a') {
            uc++;
        }
        else {
            lc++;
        }
    }
    cout << ((uc > lc) ? u : l) << endl; 

    return 0;
}