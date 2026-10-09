//
// Created by JMKov on 2/24/2024.
//
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << pow(3, m) << " ";
        double ar = sqrt(3) * n / 4 * n;
        long long v = round(ar * pow(0.75, m) * 100);
        cout << v / 100 << "." << (v/10) % 10 << (v % 10) << endl;
    }
    return 0;
}