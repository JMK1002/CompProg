#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int tens = 0;
    long long a = 10;
    while (n--) {
        a += 9;
        while (true) {
            int sum = 0;
            string s = to_string(a);
            for (char c : s) {
                sum += c - '0';
            }
            if (sum == 10) {
                break;
            }
            else {
                a += 9;
            }
        }
    }
    cout << a << endl;
    return 0;
}
//19 28 37 46 55 64 73 82 91 109 118 127 136 145 154 163 172 181 190 208 217 226 235 244 253 262 271 280 307