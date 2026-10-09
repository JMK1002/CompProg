//
// Created by JMKov on 5/21/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long ans = 0;
    while (a != 0 && b != 0) {
        ans += a / b;
        a %= b;
        if (a == 0) break;
        ans += b / a;
        b %= a;
    }
    cout << ans << endl;
    return 0;
}