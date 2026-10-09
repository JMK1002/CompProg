//
// Created by JMKov on 4/14/2024.
//
#include <iostream>
using namespace std;

int main() {
    long long ans = 0;
    long long n;
    cin >> n;
    long long prev = -1;
    for (long long i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (i == 0) prev = x;
        ans += max((long long) 0, prev - x);
        prev = max(x, prev);
    }
    cout << ans << endl;
    return 0;
}