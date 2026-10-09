//
// Created by JMKov on 3/21/2023.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;
    a--;
    b--;
    cout << (s[a] != s[b]) << endl;
    return 0;
}