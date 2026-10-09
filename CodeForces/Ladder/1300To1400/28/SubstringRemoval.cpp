//
// Created by JMKov on 4/10/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int a = 1;
    int b = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) {
            a++;
        }
        else {
            break;
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == s[i + 1]) {
            b++;
        }
        else {
            break;
        }
    }
//    cout << a << " " << b << endl;
    if (s[0] == s[n - 1]) {
        cout << ((long long) (a + 1) * (long long) (b + 1)) % 998244353 << endl;
    }
    else {
        cout << a + b + 1 << endl;
    }
    return 0;
}