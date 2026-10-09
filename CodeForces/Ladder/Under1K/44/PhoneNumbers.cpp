#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int eights = 0;
    for (char c : s) {
        if (c == '8') {
            eights++;
        }
    }

    cout << min(eights, n / 11) << endl;
    return 0;
}