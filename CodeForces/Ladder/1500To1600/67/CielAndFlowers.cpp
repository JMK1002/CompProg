//
// Created by JMKov on 5/26/2023.
//
#include <iostream>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int ans = 0 + (r - 0) / 3 + (b - 0) / 3 + (g - 0) / 3;
    for (int v = 0; v < 3; v++) {
        if (min(min(r, b), g) < v) {
            ans = max(ans, (r - v) / 3 + (b - v) / 3 + (g - v) / 3);
        }
        else {
            ans = max(ans, v + (r - v) / 3 + (b - v) / 3 + (g - v) / 3);
        }
    }
    cout << ans << endl;
    return 0;
}