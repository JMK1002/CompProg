//
// Created by JMKov on 7/26/2023.
//
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> k >> n;
    cout << (6 * k - 1) * n << endl;
    for (int i = 0; i < k; i++) {
        cout << n * (6 * i + 1) << " " << n * (6 * i + 2) << " " << n * (6 * i + 3) << " " << n * (6 * i + 5) << endl;
    }
    return 0;
}
// 1 2 3 5
// 6 7 9 11
// 12 13 17 19