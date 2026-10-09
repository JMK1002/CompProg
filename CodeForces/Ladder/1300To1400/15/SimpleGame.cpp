//
// Created by JMKov on 4/6/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cout << (n == 1 ? 1 : m > n - m ? m - 1 : m + 1) << endl;
    return 0;
}