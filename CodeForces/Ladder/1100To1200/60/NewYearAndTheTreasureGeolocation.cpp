//
// Created by JMKov on 3/26/2023.
//
#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long x = 0;
    long long y = 0;
    for (int i = 0; i < 2 * n; i++) {
        int a, b;
        cin >> a >> b;
        x += a;
        y += b;
    }
    x /= n;
    y /= n;
    cout << x << " " << y << endl;
    return 0;
}