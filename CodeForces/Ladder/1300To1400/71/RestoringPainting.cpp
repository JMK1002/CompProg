//
// Created by JMKov on 4/25/2023.
//
#include <iostream>
using namespace std;

int main() {
    long long n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i + b - c;
        int k = j + a - d;
        int l = k + c - b;
        if (l == i + a - d &&
                j >= 1 && j <= n &&
                k >= 1 && k <= n &&
                l >= 1 && l <= n
        ) {
            ans++;
        }
    }
    cout << ans * n << endl;
    return 0;
}