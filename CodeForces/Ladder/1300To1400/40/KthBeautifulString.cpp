//
// Created by JMKov on 4/14/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        int a = 0;
        int b1Pos = n - (int) ((1 + sqrt(1 + 8 * (k - 1))) / 2) - 1;
        int b2Pos = n - k + (n - b1Pos - 2) * (n - b1Pos - 1) / 2;
        string s;
        for (int i = 0; i < b1Pos; i++) {
            s += "a";
        }
        s += "b";
        for (int i = b1Pos + 1; i < b2Pos; i++) {
            s += "a";
        }
        s += "b";
        for (int i = b2Pos + 1; i < n; i++) {
            s += "a";
        }
        cout << s << endl;
    }
    return 0;
}