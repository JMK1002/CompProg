//
// Created by JMKov on 5/12/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long val = 1;
    long long asdf = 1;
    for (int i = 0; i < n; i++) {
        val *= 27;
        asdf *= 7;
        asdf %= 1000000007;
        val %= 1000000007;
    }
    val -= asdf;
    if (val < 0) {
        val += 1000000007;
    }
    cout << val << endl;
    return 0;
}