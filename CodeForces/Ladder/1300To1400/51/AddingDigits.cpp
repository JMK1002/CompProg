//
// Created by JMKov on 4/18/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, n;
    string s;
    cin >> a >> b >> n;
    int mod = (b - a * 10 % b) % b;
    if (mod >= 10) {
        cout << -1 << endl;
        return 0;
    }
    else {
        s.append(to_string(mod));
    }
    for (int i = 0; i < n - 1; i++) {
        s.append("0");
    }
    cout << a << s << endl;
    return 0;
}