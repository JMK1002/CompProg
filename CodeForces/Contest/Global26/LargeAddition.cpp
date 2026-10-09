//
// Created by JMKov on 6/9/2024.
//
#include <iostream>
using namespace std;


bool solve(long long x) {
    if (x == -1) return false;
    if (x == 0) return true;
    long long end = x % 10;

    for (long long i = max(end + 1, (long long) 5); i <= 9; i++) {
        if ((10 + end - i) % 10 < 5) continue;
        return solve(x / 10 - 1);
    }
    return false;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long x;
        cin >> x;
        bool ans = solve(x);
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}