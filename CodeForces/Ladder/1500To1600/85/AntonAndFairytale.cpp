//
// Created by JMKov on 6/1/2023.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double n, m;
    cin >> n >> m;
    long double t = (-1 * (2 * m - 1) - sqrt((2 * m - 1) * (2 * m - 1) - 4 * (m * m - 2 * n + m))) / -2;
    cout << (long long) ceil(t) << endl;
    return 0;
}