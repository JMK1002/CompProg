//
// Created by JMKov on 3/23/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int count = 0;
    if (b.length() > a.length()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < a.length() - b.length() + 1; i++) {
        bool works = true;
        for (int j = 0; j < b.length(); j++) {
            if (a[i + j] != b[j]) {
                works = false;
                break;
            }
        }
        if (works) {
            i += b.length() - 1;
            count++;
        }
    }
    cout << count << endl;

    return 0;
}