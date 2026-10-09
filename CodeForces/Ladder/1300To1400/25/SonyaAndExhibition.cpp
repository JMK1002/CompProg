//
// Created by JMKov on 4/9/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string s = "";
    while (n--) {
        s += (n % 2 == 0) ? '1' : '0';
    }
    cout << s << endl;
    return 0;
}