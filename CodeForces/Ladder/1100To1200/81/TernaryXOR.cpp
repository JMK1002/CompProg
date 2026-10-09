//
// Created by JMKov on 4/1/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        string s;
        cin >> n >> s;
        string a = "1";
        string b = "1";
        bool equal = true;
        for (int i = 1; i < n; i++) {
            switch (s[i] - '0') {
                case 0:
                    a += "0";
                    b += "0";
                    break;
                case 1:
                    if (equal) {
                        a += "1";
                        b += "0";
                        equal = false;
                    }
                    else {
                        a += "0";
                        b += "1";
                    }
                    break;
                case 2:
                    if (equal) {
                        a += "1";
                        b += "1";
                    }
                    else {
                        a += "0";
                        b += "2";
                    }
                    break;
            }
        }
        cout << a << endl;
        cout << b << endl;
    }
    return 0;
}