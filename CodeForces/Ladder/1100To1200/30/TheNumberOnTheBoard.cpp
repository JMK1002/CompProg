#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    string s;
    cin >> k >> s;
    int sum = 0;
    int digAmnts[10] = {0};
    for (char c : s) {
        sum += c - '0';
        digAmnts[c - '0']++;
    }

    if (sum >= k) {
        cout << 0 << endl;
        return 0;
    }

    int a = k - sum;
    int b = 0;
    for (int i = 0; i < 9; i++) {
        if (a - (digAmnts[i] * (9 - i)) <= 0) {
            cout << b + (a / (9 - i) - (a % (9 - i) == 0)) + 1 << endl;
            return 0;
        }
        else {
            a -= (digAmnts[i] * (9 - i));
            b += digAmnts[i];
        }
    }
    
    return 0;
}