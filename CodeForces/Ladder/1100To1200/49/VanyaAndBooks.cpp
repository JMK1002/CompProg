//
// Created by JMKov on 3/23/2023.
//
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    unsigned long long ans = 0;
    int l = (int) log10(n) + 1;
    for (int i = 1; i < l; i++) {
        ans += (unsigned long long) pow(10, i - 1) * 9 * i;
    }
    ans += l * (n - (unsigned long long) pow(10, l - 1) + 1);
    cout << ans << endl;
    return 0;
}